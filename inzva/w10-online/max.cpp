// g++ -std=c++14 -O2 -Wall qa.cpp
// Very inefficeient -> check max2 solution
#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef vector<int>		VI;
typedef vector<bool>  	VB;
typedef vector<ll>  	VLL;
typedef pair<int, int>  PII;
typedef pair <ll, ll>  	PLL;
typedef vector<PII>  	VPII;
typedef tuple<int,int,int>  TI;

typedef unordered_set<int> USI;
typedef set<int> SI;

typedef unordered_map<int, int> UMP;
typedef map<int, int> MP;

typedef queue<int> QI;
typedef queue<PII> QP;

typedef priority_queue<int> PQI;
typedef priority_queue<PII> PQP;

#define sc(n)		scanf("%d",&n)
#define sc2(i,j)	scanf("%d%d",&i,&j)
#define sc3(i,j,k)	scanf("%d%d%d",&i,&j,&k)
#define scl(n) 		scanf("%lld",&n)
#define scf(n) 		scanf("%lf",&n)
#define scs(n)  	scanf("%s",n)

#define FOR(i,x,y) 	for(int i=(x); i<=(y); i++)
#define REV(i,x,y) 	for(int i=(x); i>=(y); i--)
#define ALL(v) 		(v).begin(),(v).end()
#define SZ(v) 		(int)v.size()

#define PR(i)		printf("%d\n", (i))
#define PRL(i)		printf("%lld\n", (i))
#define PRA(arr)	FOR(i,0,(arr.size()-1)){ cout << arr[i] << " ";} cout << "\n"
#define PRV(v)		for(auto i : v) { cout << i << " ";} cout << "\n"

#define DBG2(i,j)	cout <<"DBG: "<< i << " " << j << endl
#define DBG3(i,j,k)	cout <<"DBG: "<< i << " " << j << " " << k << endl

#define bit(x,i) (x&(1<<i)) //ith bit of x;
#define ceilint(a,k) ((a-1)/k + 1) // round up a/k
#define min3(x,y,z) min(x,min(y,z))
#define max3(x,y,z) max(x,max(y,z))

#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define mod 1000000007

#define nmax 50004
ll sumtree[4*nmax];
int mxtree[4*nmax];

void update(int i, int l, int r, int x, int val){
    if(r == x &&  l == x){ // leaf
        sumtree[i] = val;
        mxtree[i] = val;
        return;
    }

    if(x < l || r < x){ // out of range
        return;
    }

    int mid = (r+l)/2;
    update(2*i, l, mid, x, val);
    update(2*i+1, mid+1, r, x, val);
    sumtree[i] = sumtree[2*i] + sumtree[2*i+1];
    mxtree[i] = max(mxtree[2*i], mxtree[2*i+1]);
}

int querySum(int i, int l, int r, int ql, int qr){
    if(r < ql || qr < l){ // segment lr not in range qlr
        return 0;
    }

	// segment lr fully inside in range qlr
    if(ql <=l && r <= qr) return sumtree[i];

    int mid = (r+l)/2;
    int lval = querySum(2*i, l, mid, ql, qr);
    int rval = querySum(2*i+1, mid+1, r, ql, qr);
    return (lval + rval) ;
}

int queryMax(int i, int l, int r, int ql, int qr){
    if(r < ql || qr < l){ // segment lr not in range qlr
        return 0;
    }

	// segment lr fully inside in range qlr
    if(ql <=l && r <= qr) return mxtree[i];

    int mid = (r+l)/2;
    int lval = queryMax(2*i, l, mid, ql, qr);
    int rval = queryMax(2*i+1, mid+1, r, ql, qr);
    return max(lval,rval) ;
}

int indexMax(int i, int l, int r, int x){
    if(r == l){ // leaf
        if(mxtree[i] == x) return r;
        else return -1;
    }

    if(mxtree[i] < x) return -1;

    int mid = (r+l)/2;
    int lval = indexMax(2*i, l, mid, x);
    if(lval > 0) return lval;
    int rval = indexMax(2*i+1, mid+1, r, x);
    return rval;
}
// Very inefficeient -> check max2 solution
int main() {
    int t; sc(t);
    int n, x;
    while(t--){
        memset(sumtree, 0, sizeof(ll));
        memset(mxtree, 0, sizeof(int));
        sc(n);
        FOR(i,1,n){
            sc(x);
            update(1,1,n,i,x);
        }
        int i = 1;
        ll res = 0;
        while(i < n){
            int mx = queryMax(1,1,n,i,n);
            int imx = indexMax(1,1,n,mx);
            if(imx == i){
                i++;
                continue;
            }
            else{
                ll sum = querySum(1,1,n,i,imx-1);
                ll ct = imx -i;
                res += (ct*mx);
                res -= sum;
                i = imx+1;
            }
        }
        PRL(res);

    }

	return 0;
}
