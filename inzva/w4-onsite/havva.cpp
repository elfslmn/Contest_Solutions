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


VI pre,post;
VI adj[10005];
bool vis[10005];

void getpre(int p){
   vis[p] = true;
   pre.pb(p);
   sort(adj[p].begin(), adj[p].end());
   for(auto c: adj[p]){
      if(vis[c]) continue;
      getpre(c);
   }
}

void getpost(int p){
   vis[p] = true;
   sort(adj[p].begin(), adj[p].end());
   for(auto c: adj[p]){
      if(vis[c]) continue;
      getpost(c);
   }
   post.pb(p);
}


int main() {
   int t; sc(t);
   int n, u,v;
   while(t--){
      sc(n);
      FOR(i,1,n-1){
         sc2(u,v);
         adj[u].pb(v);
      }
      sort(adj[1].begin(), adj[1].end());
      int l = adj[1][0];
      int r = adj[1][1];

      getpre(l);
      getpost(r);
      for(auto i : pre){
         printf("%d ",i);
      }
      printf("1 ");
      for(auto i : post){
         printf("%d ",i);
      }
      printf("\n");

      pre.clear();
      post.clear();
      MEM(vis);
      FOR(i,0,n){
         adj[i].clear();
      }

   }



	return 0;
}
