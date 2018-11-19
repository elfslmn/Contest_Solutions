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

#define nmax 1005

vector<pair<int, PII>> adj[nmax];
double leaf[nmax];

double solve(int i, int t){
   if(leaf[i] != -1){
      if(t == 1){
         return sqrt(leaf[i]);
      }
      else{
         return leaf[i];
      }
   }
   else{
      double res = 0;
      for(auto c: adj[i]){
         res = max(res, solve(c.fi, c.se.se)/c.se.fi*100);
      }
      if(t == 1) return sqrt(res);
      else return res;
   }
}

int main() {
   int n; sc(n);
   int a,b,x,t;

   FOR(i,1,n-1){
      sc2(a,b); sc2(x,t);
      adj[a].pb({b,{x,t}});
   }

   FOR(i,1,n){
      scf(leaf[i]);
   }

   double res = solve(1,0);
   PRF(res);

	return 0;
}
