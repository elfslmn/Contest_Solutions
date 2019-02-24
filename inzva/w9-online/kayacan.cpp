// g++ -std=c++14 -O2 -Wall qa.cpp
// /usr/bin/time -v ./a.out
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

#define nmax 100005
int tree[4*nmax];
bool lazy[4*nmax];

void update(int i, int l, int r, int ql, int qr){ // flip the range
    // !! out of range cond. CANNOT be here
    // apply lazy
    if(lazy[i]){
        tree[i] = (r-l+1) - tree[i];
        if(r != l){ // not leaf
            lazy[2*i] = !lazy[2*i];
            lazy[2*i+1] = !lazy[2*i+1];
        }
        lazy[i] = false;
    }

    if(r < ql || qr < l){ // lr out of range qlr
        return; // lazy should be applied even if out of range
    }

    if(ql <= l && r <= qr){ // lr fully inside qlr
        tree[i] = (r-l+1) - tree[i];
        if(r != l){ // not leaf
            lazy[2*i] = !lazy[2*i];
            lazy[2*i+1] = !lazy[2*i+1];
        }
        return;
    }

    int mid = (l+r)/2;
    update(2*i, l, mid, ql, qr);
    update(2*i+1, mid+1, r, ql, qr);
    tree[i] = tree[2*i] + tree[2*i+1];
}

int query(int i, int l, int r, int x){
    // out of range cond. can be here
    // apply lazy
    if(lazy[i]){
        tree[i] = (r-l+1) - tree[i];
        if(r != l){ // not leaf
            lazy[2*i] = !lazy[2*i];
            lazy[2*i+1] = !lazy[2*i+1];
        }
        lazy[i] = false;
    }

    if(r < x){ // out of range
        return -1;
    }

    if(tree[i] == 0){ // there is no 1 bit in range lr
        return -1;
    }

    if(r == l){ // leaf
        if(tree[i]) return r;
        else return -1;
    }

    int mid = (l+r)/2;

    //printf("range, l-r = %d-%d dallan\n", l,r);

    int res = query(2*i, l, mid, x);
    //printf("left of %d-%d returned %d\n", l,r,res);
    if(res == -1){
        res = query(2*i+1, mid+1, r, x);
        //printf("right of %d-%d returned %d\n", l,r,res);
    }

    return res;
}


int main() {
    int n,m; sc2(n,m);
    int t, x,y;

    FOR(i,1,m){
        sc(t);
        //cout << "DBG " << ((t==1) ? "update":"query" ) << endl;
        if(t == 1){
            sc2(x,y);
            if(x >y) swap(x,y);
            update(1,1,n,x,y);
        }
        else if(t == 2){
            sc(x);
            int res = query(1,1,n,x);
            if(res == -1) PR(n+1);
            else PR(res);
        }

        /*cout << "tree: ";
        FOR(i,1,4*n){
            cout << tree[i] << ",";
        }
        cout <<endl; */
    }


	return 0;
}
