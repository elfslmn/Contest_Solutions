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

#define N 100005
#define INF 1000000000000000
bool proc[N];					// if node is proccessed
ll dist[N]; 					// min distance to start node
vector<pair<int,int>> adj[N];   // weighted adjacency vector

void djk(int x, int n){
	for (int i = 1; i <= n; i++) {
      dist[i] = INF;
      proc[i] = false;
   }
	dist[x] = 0;
	priority_queue<pair<ll,int>> q;
	q.push({0,x});
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		if (proc[a]) continue;
		proc[a] = true;	// at this point dist[a] has minimum value and wont change anymore

		for (auto u : adj[a]) {
			int b = u.first, w = u.second;

			if (dist[a]+w < dist[b]) {
				dist[b] = dist[a]+w;
				q.push({-dist[b],b});
			}
		}
	}
}

int main() {
   int n, m; sc2(n,m);
   int u, v, w;
   FOR(i,1,m){
      sc3(u,v,w);
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
   }
   int q; sc(q);
   vector<pair<int,int>> us;
   int vs[q];
   FOR(i, 0, q-1){
      sc2(u,v);
      if(u>v) swap(u,v);
      us.push_back({u, i});
      vs[i] = v;
   }
   int prev = -1;
   sort(us.begin(), us.end());
   ll res[q];
   FOR(j, 0, q-1){
      int i = us[j].se;
      int u = us[j].fi;
      int v = vs[i];
      if(prev != u){
         djk(u, n);
      }
      res[i] = dist[v];
      prev = u;
   }
   FOR(j, 0, q-1){
      printf("%lld\n",res[j] );
   }



	return 0;
}
