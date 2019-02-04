"GRAPHS"
// Graph Representation
#define N 10 			//number of vertices
vector<int> adj[N];		// adjacency list    adj[i][j]   : jth neighbor of the ith node
vector<PII> edges; 		// edges vector 	 edges[i]    : ith edges from edges[i].first to edges[i].second

vector<PII> adj[N];  				// weighted adjacency vector
int adj[N][N]; 		 				// weighted adjacency matrix  adjMat[i][j]: the edge between i and j
vector<tuple<int,int,int>> edges;	// weighted edges vector
____________________________________________________________________________________________________________

// Graph Treversals Applications ***
1- If graph is connected ?  (there is a path between any two nodes)
apply dfs, eğer # of vis. nodes = all nodes -> connected

2- Cycle finding
eğer # of edges >= # of nodes -> definitely there is a cycle
değilse, cycle olabilir -> check by treversal

3- Bipartiness check (nodes can be colored by two colors so that there are no adj nodes with the same color)
apply bfs, give color to childen differnt than you.
graph is bipartite exactly when it does not contain a cycle with an odd number of edges.

//Graph treversal - use adjacecny VECTOR rep. ( VI adj[n] )_______________________________
"DFS"
bool vis[N];

void dfs(int x) {
	vis[x] = true;
	// process node x here
	for (auto u: adj[x]) {
		if (vis[u.fi]) continue;
		dfs(u.fi);
	}
}
____________________________________________________________
"BFS"
queue<int> q;
vector<int> dist(n+1,INF);
vector<bool> vis(n+1,false);

vis[x] = true; // x start node
dist[x] = 0;
q.push(x);

while (!q.empty()) {
	int cur = q.front(); q.pop();
	// process current node
	for (auto nei : adj[cur]) {
		int u = nei.fi;
		int w = nei.se;
		if (vis[u]) continue;
		vis[u] = true;
		dist[u] = dist[s]+w;
		q.push(u);
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
dist[x] = 0;	// x : start node

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

vector<int> dist(n+1,INF);
vector<bool> vis(n+1,false);
priority_queue<PII> q;

distance[x] = 0;
q.push({0,x});

while (!q.empty()) {
	int cur = q.top().second; q.pop();
	if (vis[cur]) continue;
	vis[cur] = true;	// at this point dist[cur] has minimum value and wont change anymore

	for (auto nei : adj[cur]) {
		int u = nei.first
		int w = nei.second;

		if (dist[cur]+w < dist[u]) {
			dist[u] = dist[cur]+w;
			q.push({-dist[u],u});
		}
	}
}

//_________________________________________________________________________

// 3 - FLOYD WARSHALL 	O(n^3)
// use adj matrix
// finds all pairs of min distances
// n: number of nodes

int adj[N][N];
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

2- Kruskal's algorithm O(m+ nlogn)
	- edgeleri weightlerine göre sırala (use edge list rep.)
	- başta hiç edge yok
	- küçükten başlayarak eğer edge cycle olusturmuyorsa ekle.
	- better for sparse graphs ( node fazla, edge az)

//_________________________________________________________________________________

// Kruskal MSP
int link[n+1];
int size[n+1];

//find returns the representative for an element x
int find(int x) {
	while (x != link[x]) x = link[x];
	return x;
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (size[a] < size[b]) swap(a,b);
	size[a] += size[b];
	link[b] = a;
}

//checks whether elements a and b belong to the same set
bool same(int a, int b) {
	return find(a) == find(b);
}

//Kruskal's Minimum spanning tree
//edgeleri uzunluğuna göre küçükten buyuge sırala

// initialize
FOR(i,0,n){
	link[i] = i;
	size[i] = 1;
}
// construct graph
for (edge btw a and b) {
	if (!same(a,b)) unite(a,b);
}
_____________________________________________________________________________________

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
