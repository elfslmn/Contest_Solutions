// g++ -std=c++14 -O2 -Wall qa.cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>  VI;
typedef pair<int, int>  PII;
typedef pair <ll, ll>  PLL;
typedef vector<pair<int, int>>  VPII;

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
#define DBGA(arr) 	FOR(i,0,(arr.size()-1)){ cout << arr[i] << " ";} cout << "\n";

#define emb emplace_back
#define em emplace
#define fi first
#define se second
// not for long
#define infi 0x3f3f3f3f
#define infd (double)(1.0)/(0.0);

# define MOD 998244353
int add(int a, int b){
   int sum = a+b;
   if(sum > MOD) sum-= MOD;
   return sum;
}

int mul(int a, int b)
{
    ll res = 0; // Initialize result
    a = a % MOD;
    while (b > 0)
    {
        if (b % 2 == 1) res = (res + a) % MOD;
        a = (a * 2) % MOD;
        b /= 2;
    }
    return res % MOD;
}

int n,k;

int dp(int curk, int prevBlock, int curn){
   if(curn == n) return curk;
   if(curk >= k) return 0;

   if(prevBlock == 1){
      int m1 = dp(curk +2, 1, curn+1);
      int m2 = dp(curk, 2, curn+1);
      return add(m1,m2);
   }
   else if(prevBlock == 2)
   {
      int m1 = dp(curk, 1, curn+1);
      int m2 = dp(curk+1, 2, curn+1);
      return add(m1,m2);
   }
}

int main() {
   sc2(n,k);
   int m1 = dp(2, 1, 1);
   int m2 = dp(1, 2, 1);
   int res = add(m1,m2);
   res = mul(res,2);
   printf("%d\n", res);

	return 0;
}
