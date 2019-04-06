// g++ -std=c++14 -O2 -Wall qa.cpp
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

long long fastExp(long long n, long long k){
	if(k == 0) return 1;
	if(k == 1) return n;

	long long temp = fastExp(n, k/2);

	// If k is odd return n * temp * temp
	// If k is even return temp * temp
	if((k&1) == 1) // odd
		return (n * temp * temp) % mod;
	else // even
		return (temp * temp) % mod;
}
ll a[1004];
ll dp[1004];

int main() {
	int t; sc(t);
    while(t--){
        int n,m; sc2(n,m);
        a[1] = 1;
        a[2] = 2;
        a[3] = 4;
        a[4] = 8;
        FOR(i,5,m){
            a[i] = (a[i-1] + a[i-2]) %mod;
            a[i] =  (a[i] + a[i-3]) %mod;
            a[i] =  (a[i] + a[i-4]) %mod;
        }
        FOR(i,1,m){
            a[i] = fastExp(a[i], n);
        }
        FOR(i,1,m){
            dp[i] = a[i];
            FOR(j,1,i-1){
                dp[i] -= ((dp[j]*(a[i-j]))%mod);
                if(dp[i] < 0) dp[i] += mod;
            }
        }
        PRL(dp[m]);
        FOR(i,1,m){
            a[i] = 0;
            dp[i] = 0;
        }

    }
	return 0;
}
