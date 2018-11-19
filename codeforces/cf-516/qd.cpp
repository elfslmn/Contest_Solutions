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
#define infd (double)(1.0)/(0.0);

char gr[2005][2005];
int x,y;
int n, m;
int res = 0;

void solve(int cr, int cc){
   //DBG2(cr,cc);
   if(cr < 0 || cr >= n || cc < 0 || cc >= m){
      return;
   }
   if(gr[cr][cc] == '*' || gr[cr][cc] == '+') return;

   if(gr[cr][cc] == '.'){
      res++;
      gr[cr][cc] = '+';
   }

   solve(cr+1, cc);
   solve(cr-1, cc);

   if(x > 0){
      x--;
      solve(cr, cc-1);
      x++;
   }

   if(y > 0){
      y--;
      solve(cr, cc+1);
      y++;
   }
}

int main() {
   sc2(n,m);
   int r,c;  sc2(r,c);
   sc2(x,y);
   FOR(i, 0, n-1){
      scanf("%s", gr[i]);
   }
/*FOR(i, 0, n-1){
      FOR(j,0,m-1){
         printf("%c",gr[i][j]);
      }
      printf("\n");
   }*/

   solve(r-1,c-1);
   PR(res);

   FOR(i, 0, n-1){
      FOR(j,0,m-1){
         printf("%c",gr[i][j]);
      }
      printf("\n");
   }


	return 0;
}
