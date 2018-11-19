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

typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

int main() {
   int n, h, g, t;
   sc2(n,g); sc2(h,t);
   vvi gr(n,vector<int>(n,0));

   int r,c;
   while(g--){ // -1: tomatoes
      sc2(r,c);
      gr[r][c] = -1;
   }
   while(h--){ // 1: homes
      sc2(r,c);
      gr[r][c] = 1;
   }

   int d, x,y;
   VI res(2*n-1,0);
   vvb vis(n,vector<bool>(n,false));
   vvi dist(n,vector<int>(n,0));
   queue<PII> q;
   vis[0][0] = true;
   q.push({0,0});
   while (!q.empty()) {
      PII cur = q.front(); q.pop();
      x = cur.fi; y=cur.se;
      d = dist[x][y];
      if(gr[x][y] == 1) {
         res[d]++;
         //printf("Home found at %d,%d with distance %d: res[%d] = %d\n", x,y,d,d,res[d]);
      }
      // left
      if(x> 0 && vis[x-1][y] == false && gr[x-1][y] != -1){
         vis[x-1][y] = true;
         dist[x-1][y] = dist[x][y]+1;
         q.push({x-1,y});
      }
      // right
      if(x< n-1 && vis[x+1][y] == false && gr[x+1][y] != -1){
         vis[x+1][y] = true;
         dist[x+1][y] = dist[x][y]+1;
         q.push({x+1,y});
      }
      // top
      if(y> 0 && vis[x][y-1] == false && gr[x][y-1] != -1){
         vis[x][y-1] = true;
         dist[x][y-1] = dist[x][y]+1;
         q.push({x,y-1});
      }
      // bottom
      if(y < n-1 && vis[x][y+1] == false && gr[x][y+1] != -1){
         vis[x][y+1] = true;
         dist[x][y+1] = dist[x][y]+1;
         q.push({x,y+1});
      }

   }
   FOR(i,0,n){
      res[i+1] = res[i+1]+res[i];
   }
   while(t--){
      sc(d);
      PR(res[d]);

   }

	return 0;
}
