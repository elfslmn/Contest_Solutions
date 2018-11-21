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

vector<string> grid;
bool vis[3004][3004];
VPII moves = {{-1,-1}, {-1,0},{-1,1},{1,1},{1,0},{1,-1},{0,1},{0,-1} };
int a,b,n,p;

int findSize(int r, int c){
   if(vis[r][c]) return -1;
   vis[r][c] = true;

   queue<PII> q;
   q.push({r,c});
   int size = 0;

   while(!q.empty()){
      PII cur = q.front(); q.pop();
      size++;
      for(auto m: moves){
         PII nx = {cur.fi + m.fi, cur.se + m.se};
         if(nx.fi<0 || nx.fi>= a || nx.se<0 || nx.se>=b) continue;
         if(grid[nx.fi][nx.se] != '1') continue;
         if(vis[nx.fi][nx.se]) continue;

         vis[nx.fi][nx.se] = true;
         q.push(nx);
      }

   }
   return size;
}

int main() {
   sc2(n,p);
   int sz[n];
   FOR(i,0,n-1){
      sc(sz[i]);
   }
   VPII oneLocs;
   sc2(a,b);
   grid.resize(a, string(b,0));
   for(auto &row : grid) cin >> row;

   FOR(i,0,a-1){
      FOR(j, 0, b-1){
         if(grid[i][j] == '1') oneLocs.pb({i,j});
      }
   }

   VI islandsizes;
   for(PII one: oneLocs){
      int res = findSize(one.fi, one.se);
      if(res == -1) continue;
      islandsizes.pb(res);
   }
   if(islandsizes.size() < n){
      PR(-1);
      return 0;
   }

   sort(islandsizes.begin(), islandsizes.end());
   reverse(islandsizes.begin(), islandsizes.end());
   sort(sz, sz+n);
   reverse(sz, sz+n);
   FOR(i,0,n-1){
      if(sz[i]> islandsizes[i]){
         PR(-1);
         return 0;
      }
   }
   PRL(n*1ll*p);

	return 0;
}
