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
#define DBGA(arr) 	FOR(i,0,(arr.size()-1)){ cout << arr[i] << " ";} cout << "\n";

#define pb push_back
#define fi first
#define se second
// not for long
#define infi 0x3f3f3f3f
#define infd (double)(1.0)/(0.0)

const int mod = 1e9 +7;

// Extended Euclidean Algorithm  O(logm)
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
	{
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

// Recursive - function to find modulo inverse of a
int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else{
        // m is added to handle negative x
        return (x%m + m) % m;
    }
}

int solve(int p, int q, int n){
   DBG2(p,q);
   if(n == 1){
      ll res = (p*modInverse(q,mod))%mod;
      cout << " n == 1 "<<endl <<"p, qinv ";
      DBG3(p, modInverse(q,mod), res);
      return res;
   }

   int temp = solve(p,q,n/2);

   if(n%2 == 0){ // even
      ll a = (2*temp) % mod;
      ll b = (1 - temp^2)%mod;
      cout << " n == even "<<endl <<"a,b, binv ";
      DBG3(a,b,modInverse(b,mod));

      return (a*modInverse(b,mod))%mod;
   }
   else{
      ll a = (2*temp) % mod;
      ll b = (1 - temp^2)%mod;
      ll twotemp = (a*modInverse(b,mod))%mod;
      ll tx = (p*modInverse(q,mod))%mod;
      a = (twotemp + tx)%mod;
      b = (1 - twotemp*tx)%mod;
      return (a*modInverse(b,mod))%mod;
   }

}

int main() {
   int t; sc(t);
   int p,q,n;
   FOR(i,1,t){
      sc3(p,q,n);
      int res = solve(p,q,n);
      if(res < 0) res+= mod;
      PR(res);
   }



	return 0;
}
