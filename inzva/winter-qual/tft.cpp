// g++ -std=c++14 -O2 -Wall qa.cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>  VI;
typedef pair<int, int>  PII;
typedef pair <ll, ll>  PLL;
typedef vector<pair<int, int> >  VPII;

typedef unordered_set<int> USI; // use emplace
typedef set<int> SI;

typedef unordered_map<int, int> UMP;
typedef map<int, int> MP;

typedef priority_queue<int> PQ; // use emplace
typedef priority_queue<pair<int,int>> PQP;

#define sc(n)		scanf("%d",&n)
#define sc2(i,j)	scanf("%d%d",&i,&j)
#define sc3(i,j,k)	scanf("%d%d%d",&i,&j,&k)
#define scl(n) 		scanf("%lld",&n)
#define scf(n) 		scanf("%lf",&n)
#define scs(n)  	scanf("%s",n)

#define FOR(i,x,y) 	for(int i=(x); i<=(y); i++)
#define REV(i,x,y) 	for(int i=(x); i>=(y); i--)

#define MEM(a)		memset(a,0,sizeof(a))
#define MINUS(a)	memset(a,0xff,sizeof(a))
#define MINF(a)		memset(a,0x3f,sizeof(a))

#define PR(i)		printf("%d\n", (i))
#define PRL(i)		printf("%lld\n", (i))
#define PRF(i)		printf("%.10f\n", (i))

#define DBG2(i,j)	cout << i << " " << j << endl
#define DBG3(i,j,k)	cout << i << " " << j << " " << k << endl
#define DBGA(arr) 	FOR(i,0,(arr.size()-1)){ cout << arr[i] << " ";} cout << "\n"

#define pb push_back
#define fi first
#define se second
// not for long
#define infi 0x3f3f3f3f
#define infd (double)(1.0)/(0.0)

ll mod = 1000000007;

vector<ll> p(100005,0);

ll fastExp(ll k){
	if(k == 0) return 1;
	if(k == 1) return 2;
    if(p[k] != 0) return p[k];

	ll temp = fastExp(k/2);
    temp %= mod;

	if((k&1) == 1){ // odd
        p[k] = (2 * temp * temp) % mod;
		return p[k];
    }
	else{ // even
        p[k] = (temp * temp) % mod;
		return p[k];
    }
}

int main() {
    int n; sc(n);

    vector<ll> c(n+1,0);
    c[5] = 2;
    FOR(i,6,n){
        c[i] = (c[i-1]*2) % mod;
        c[i] = (c[i] + fastExp(i-5))%mod;
        c[i] = (c[i] - c[i-5]) %mod;
        if(c[i]<0) c[i] += mod;
    }
    PRL(c[n]);
    /*FOR(i,0,n){
        printf("%lld,",c[i]);
    }
    cout << endl;
    FOR(i,0,n){
        printf("%lld,",p[i]);
    }
    cout << endl;*/


	return 0;
}
