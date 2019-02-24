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

ll tree[4*nmax];
ll lazy[4*nmax];

void update(int i, int l, int r, int ql, int qr, ll val){ // val = change
    // !! out of range cond. CANNOT be here
    // apply lazy
    if(lazy[i]){
        tree[i] += (lazy[i]*(r-l+1));
        if(r != l){ // not leaf
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }

    if(r < ql || qr < l){ // lr out of range qlr
        return; // lazy should be applied even if out of range
    }

    if(ql <= l && r <= qr){ // lr fully inside qlr
        tree[i] += ((r-l+1)*val);
        if(r != l){ // not leaf
            lazy[2*i] += val;
            lazy[2*i+1] += val;
        }
        return;
    }

    int mid = (l+r)/2;
    update(2*i, l, mid, ql, qr, val);
    update(2*i+1, mid+1, r, ql, qr, val);
    tree[i] = tree[2*i] + tree[2*i+1];
}

ll query(int i, int l, int r, int ql, int qr){
    // out of range cond. can be here
    // apply lazy
    if(lazy[i]){
        tree[i] += (lazy[i]*(r-l+1));
        if(r != l){ // not leaf
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }

    if(r < ql || qr < l){ // lr out of range qlr
        return 0LL;
    }


    if(ql <= l && r <= qr){ // lr fully inside qlr
        return tree[i];
    }

    int mid = (l+r)/2;
    ll lval = query(2*i, l, mid, ql, qr);
    ll rval = query(2*i+1, mid+1, r, ql, qr);
    return lval + rval;
}

int main() {
    int n,m; sc2(n,m);
    int t,l,r,val;
    FOR(i,1,m){
        sc(t);
        if(t == 1){
            sc3(l,r,val);
            update(1,1,n, l,r,val);
        }
        else if(t == 2){
            sc2(l,r);
            PRL(query(1,1,n,l,r));
        }
    }

	return 0;
}
