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


int main() {
    int n; sc(n);
    vector<PII> adj[n+1];

    int u,v,w;
    ll res = 0;
    FOR(i,1,n-1){
        sc3(u,v,w);
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        res += w;
    }
    res*=2;

    PII maxdistnode = {-1,0};
    vector<bool> vis(n+1,0);
    VI dist(n+1,0);
    queue<int> q;
    vis[1] = true;
    dist[1] = 0; // (unweighted) distance to the started node
    q.push(1);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : adj[s]) {
            int node = u.fi;
            if (vis[node]) continue;
            vis[node] = true;
            dist[node] = dist[s]+u.se;
            if(dist[node] > maxdistnode.se){
                maxdistnode = {node, dist[node]};
            }
            q.push(node);
        }
    }

    FOR(i,1,n){
        vis[i] = false;
        dist[i] = 0;
    }

    q.push(maxdistnode.fi);
    vis[maxdistnode.fi] = true;
    dist[maxdistnode.fi] = 0;
    maxdistnode.se = 0;
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : adj[s]) {
            int node = u.fi;
            if (vis[node]) continue;
            vis[node] = true;
            dist[node] = dist[s]+ u.se;
            if(dist[node] > maxdistnode.se){
                maxdistnode = {node, dist[node]};
            }
            q.push(node);
        }
    }
    PRL(res - maxdistnode.se);





	return 0;
}
