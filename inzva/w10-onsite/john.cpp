// g++ -std=c++14 -O2 -Wall qa.cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef vector<int>        VI;
typedef vector<bool>      VB;
typedef vector<ll>      VLL;
typedef pair<int, int>  PII;
typedef pair <ll, ll>      PLL;
typedef vector<PII>      VPII;
typedef tuple<int,int,int>  TI;

typedef unordered_set<int> USI;
typedef set<int> SI;

typedef unordered_map<int, int> UMP;
typedef map<int, int> MP;

typedef queue<int> QI;
typedef queue<PII> QP;

typedef priority_queue<int> PQI;
typedef priority_queue<PII> PQP;

#define sc(n)        scanf("%d",&n)
#define sc2(i,j)    scanf("%d%d",&i,&j)
#define sc3(i,j,k)    scanf("%d%d%d",&i,&j,&k)
#define scl(n)         scanf("%lld",&n)
#define scf(n)         scanf("%lf",&n)
#define scs(n)      scanf("%s",n)

#define FOR(i,x,y)     for(int i=(x); i<=(y); i++)
#define REV(i,x,y)     for(int i=(x); i>=(y); i--)
#define ALL(v)         (v).begin(),(v).end()
#define SZ(v)         (int)v.size()

#define PR(i)        printf("%d\n", (i))
#define PRL(i)        printf("%lld\n", (i))
#define PRA(arr)    FOR(i,0,(arr.size()-1)){ cout << arr[i] << " ";} cout << "\n"
#define PRV(v)        for(auto i : v) { cout << i << " ";} cout << "\n"

#define DBG2(i,j)    cout <<"DBG: "<< i << " " << j << endl
#define DBG3(i,j,k)    cout <<"DBG: "<< i << " " << j << " " << k << endl

#define bit(x,i) (x&(1<<i)) //ith bit of x;
#define ceilint(a,k) ((a-1)/k + 1) // round up a/k
#define min3(x,y,z) min(x,min(y,z))
#define max3(x,y,z) max(x,max(y,z))

#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define mod 1000000007

#define nmax 218000
int sieve[nmax+1];
int ct[nmax+1];

int main() {
    int t; sc(t);
    int n;
    int last = 1;
    for (int x = 2; x <= nmax; x++) {
        if (sieve[x]) continue;
        for (int u = 2*x; u <= nmax; u += x) {
            sieve[u] = x;
        }
    }
    while(t--){
        sc(n);
        VI dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        FOR(i,4,n){
            dp[i] = dp[i-1] + dp[i-4];
        }
        //PR(dp[n]);
        FOR(x,last+1, dp[n]){
            ct[x] = ct[x-1];
            if(sieve[x] == 0){
                ct[x]++;
            }
            //DBG2(x,ct[x]);
        }
        if(last < dp[n]) last = dp[n];
        PR(ct[dp[n]]);

    }

    return 0;
}
