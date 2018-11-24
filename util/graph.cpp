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
	// process node s
	
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
			dist[node] = dist[s]+1;
			q.push(node);
		}
	}
}
___________________________________________________________________________________

"SHORTEST PATH ALGORITHMS"

#define INF INT_MAX

// 1 - BELLMANN FORD	O(nm)
// use edges rep. , use when there is negative wieghts
// x: start node, n: number of nodes
// return false if there is a negative cycle

vector<tuple<int,int,int>> edges;
int dist[N]; // min distance to start node

bool bellmannFord(int x, int n){
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[x] = 0;
	
	// Relax all edges n-1 times
	for (int i = 1; i <= n-1; i++) {
		for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			dist[b] = min(dist[b], dist[a]+w);
		}
	}
	
	// check negative cycle with one more relaxation
	for (auto e : edges) {
		int a, b, w;
		tie(a, b, w) = e;
		dist[b] = min(dist[b], dist[a]+w);
		if (dist[a] != INF && dist[a] + w < dist[v]){
			return false;
		}
	}
	return true;
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
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else if (adj[i][j]) dist[i][j] = adj[i][j];
			else dist[i][j] = INF;
		}
	}
	
	//iterate
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j],dist[i][k]+v[k][j]);
			}
		}
	}

}










