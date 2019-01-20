#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define N 10 //number of vertices

vector<int> adj[N];				// adjacency list    adj[i][j]   : jth neighbor of the ith node
vector<PII> edges; 				// edges vector 	 edges[i]    : ith edges from edges[i].first to edges[i].second

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    
    edges.push_back({v,u});
    edges.push_back({u,v});
}

// Graph Treversals Applications
1- If graph is connected ?  (there is a path between any two nodes)
apply dfs, eğer # of vis. nodes = all nodes -> connected 

2- Cycle finding
eğer # of edges >= # of nodes -> definitely there is a cycle
değilse, cycle olabilir -> check by treversal

3- Bipartiness check (nodes can be colored by two colors so that there are no adj nodes with the same color)
apply bfs, give color to childen differnt than you.
graph is bipartite exactly when it does not contain a cycle with an odd number of edges.

//Graph treversal - use adjacecny VECTOR rep."_______________________________

bool vis[N];
int dist[N];  

void dfs(int x) {
	vis[x] = true;
	// process node x
	
	for (auto u: adj[x]) {
		if (vis[u]) continue;
		dfs(u);
	}
}

void bfs(int x) {
	queue<int> q;
	vis[x] = true;
	dist[x] = 0; 	// distance to the started node
	
	q.push(x);
	while (!q.empty()) {
		int s = q.front(); q.pop();
		// process node s
		
		for (auto u : adj[s]) {
			if (vis[u]) continue;
			vis[u] = true;
			dist[u] = dist[s]+1; 
			q.push(u);
		}
	}
}
_________________________________________________________________________________________________________

"With WEIGHTED edges"

#define N 10 //number of vertices
#define fi first
#define se second
typedef pair<int, int>  PII;

vector<PII> adj[N];  				// weighted adjacency vector 
int adj[N][N]; 		 				// weighted adjacency matrix  adjMat[i][j]: the edge between i and j
vector<tuple<int,int,int>> edges;	// weighted edges vector


void addEdge(int u, int v, int w)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
    
    adj[u][v] = w;
    adj[v][u] = w;
    
    edges.push_back({u,v,w});
    edges.push_back({v,u,w});
}

//GRAPH TREVERSALS - use adjacecny LIST rep."___________________________________

bool vis[N];
int dist[N];	

void dfs(int x) {
	vis[x] = true;
	// process node s
	
	for (auto u: adj[x]) {
		if (vis[u.fi]) continue;
		dfs(u.fi);
	}
}

void bfs(int x) {
	queue<int> q;
	vis[x] = true;
	dist[x] = 0; // (unweighted) distance to the started node 
	q.push(x);
	while (!q.empty()) {
		int s = q.front(); q.pop();
		// process node s
		for (auto u : adj[s]) {
			int node = u.fi;
			if (vis[node]) continue;
			vis[node] = true;
			dist[node] = dist[s]+u.se;
			q.push(node);
		}
	}
}
___________________________________________________________________________________

"SHORTEST PATH ALGORITHMS"

#define INF INT_MAX

// 1 - BELLMANN FORD	O(nm)
// use edges rep. , use when there is negative wieghts
// x: start node, n: number of nodes, m: number of edges
// u,v: directed node, w: edge wieght
 
        vector<tuple<int,int,int>> edges;
        // read edges
        FOR(i,1,m){
            sc3(u,v,w);
            edges.pb(make_tuple(u,v,w));
        }

        VI dist(n,INF); // dist: min distance to start node
    	dist[x] = 0;    

    	// Relax all edges n-1 times
    	for (int i = 1; i <= n-1; i++) {
    		for (auto e : edges) {
    			tie(u, v, w) = e;
    			dist[v] = min(dist[v], dist[u]+w);
    		}
    	}

    	// check negative cycle with one more relaxation
    	for (auto e : edges) {
            tie(u, v, w) = e;
            int temp = dist[v];
            dist[v] = min(dist[v], dist[u]+w);
    		if (temp != INF && dist[v] < temp){
    			printf("Negative cycle detected!");
                break;
    		}
    	}

//_________________________________________________________________________

// 2 - DIJKSTRA 	O(nlogm)
// Sum yerine min, max etc olabilir , bitwise or olamaz 
//A ->B -> C Cost (A,B)->1 (B,C) ->2 and (A,B) ->2 (Multiple edges can exist)
//In this case dijkstra from A to C will give 3(2|1). But the answer is 2(2|2).

// use adj vector, priority queue
// x: start node, n: number of nodes

bool proc[N];					// if node is proccessed
int dist[N]; 					// min distance to start node
vector<pair<int,int>> adj[N];   // weighted adjacency vector 

void djk(int x, int n){
	for (int i = 1; i <= n; i++) distance[i] = INF;
	distance[x] = 0;
	
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

//_________________________________________________________________________

// 3 - FLOYD WARSHALL 	O(n^3)
// use adj matrix
// finds all pairs of min distances
// n: number of nodes

int adj[N][N]; 		 // weighted adjacency matrix 
int dist[N][N];

void floydWarshall(int n){
	    // initialize
    FOR(i,1,n){
        FOR(j,1,n) {
            if (i == j) dist[i][j] = 0;
            else if (adj[i][j] != 0) dist[i][j] = adj[i][j];
            else dist[i][j] = INF;
        }
    }

    //iterate
    FOR(k,1,n){
        FOR(i,1,n){
            FOR(j,1,n) {
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
//_______________________________________________________________________________

"Minimum Spanning Tree (MSP)"

1- Prim's algorithm O(mlogn)
	- similar Dijkstra (keep edge weights instead of distances in pr.queue)
	- use adj. lists rep.
	- better for dense graphs ( node az, edge fazla)

2- Kruskal's algorithm O(m+ nlogn)  //check Union_find_msp file
	- edgeleri weightlerine göre sırala (use edge list rep.)
	- başta hiç edge yok
	- küçükten başlayarak eğer edge cycle olusturmuyorsa ekle.
	- better for sparse graphs ( node fazla, edge az)

//_________________________________________________________________________________

// PRIM'S MSP
	// res = min sum of edges a MSP
	VPII adj[n+1];
    vector<bool> vis(n+1, false);
    priority_queue<PII> q; // {-edge weight, node id}
    q.push({0,s});
    ll res = 0;
    while (!q.empty()) {
        int a = q.top().second;
        int wa = q.top().fi*-1;
        q.pop();
        if (vis[a]) continue;
        vis[a] = true;
        res += wa;

        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            q.push({-w,b});
        }
    }
    PRL(res);
//____________________________________________________________________________________








