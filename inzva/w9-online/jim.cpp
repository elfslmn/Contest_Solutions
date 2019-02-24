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

#define FOR(i,x,y) 	for(int i=(x); i<=(int)(y); i++)
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

#define nmax 300005
int tree[nmax * 4];

void update(int i, int l, int r, int x, int val){
    if( x > r || x < l){
        return;
    }

    if(x == r && l == r){
        tree[i] = val;
        return;
    }

    int mid = (l+r) / 2;
    update(2*i, l, mid, x,val);
    update(2*i+1, mid+1, r, x, val);
    tree[i] = max(tree[2*i] , tree[2*i+1]);
}

int query(int i, int l, int r, int ql, int qr){
    if(r < ql || qr < l){
        return 0;
    }

    if(ql <= l && r <= qr){
        return tree[i];
    }

    int mid = (l+r) / 2;
    int lval = query(2*i, l, mid, ql, qr);
    int rval = query(2*i+1, mid+1, r, ql, qr);
    return max(lval, rval);
}

vector< vector<ll> > savedVal;

ll combination(int n, int k){
	// Base condition
	if(k == n || k == 0) {
		savedVal[n][k] = 1LL;
		return savedVal[n][k];
	}

	// Base condition
	if(k == n-1 || k == 1){
		savedVal[n][k] = (long long)n;
		return savedVal[n][k];
	}

	if(savedVal[n][k] != 0)
		return savedVal[n][k];

	// Save the output of the recursion
	savedVal[n][k] = (combination(n-1, k) + combination(n-1, k-1));
	return savedVal[n][k];
}

int main() {
    int n; sc(n);
    VI arr(n+1);
    int a;
    unordered_map<int, VI> m; // <height, indices>
    int maxh = 0;
    FOR(i,1,n){
        sc(a);
        arr[i] = a;
        m[a].pb(i);
        update(1,1,n,i,a);
        maxh = max(maxh, a);
    }
    savedVal.resize(n+1, vector<ll>(3, 0LL));
    ll res = 0;
    if( m[maxh].size() >= 2) res = combination(m[maxh].size(), 2); // resi en son 2 ile carp

    for(auto cur : m){
        int h = cur.fi;
        VI ind = cur.se;
        //cout << "DBG " << h << " ind:"; PRV(ind);
        if(h == maxh) continue;

        int comb = 1;
        FOR(i,0, ind.size()-2){
            if(ind[i+1] - ind[i] == 1){ // ardisik

                comb++;
            }
            else if(ind[i+1] - ind[i] == 2){ // 1 bosluk
                if(arr[(ind[i+1] + ind[i])/2] < h){
                    comb++;
                }
                else{
                    if(comb > 1){
                        res += combination(comb, 2);
                    }
                    comb = 1;
                }
            }
            else{
                int btw = query(1,1,n,ind[i]+1, ind[i+1]-1);
                if(btw < h){
                    comb++;
                }
                else{
                    if(comb > 1){
                        res += combination(comb, 2);
                    }
                    comb = 1;
                }
            }
        }

        if(comb > 1){
            res += combination(comb, 2);
        }
    }

    PRL(res*2);


	return 0;
}
