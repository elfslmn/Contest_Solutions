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

# define INF 100000008

int main() {
    int t; sc(t);
    int n,m,u,v,w;
    while(t--){
        bool neg = false;
        sc2(n,m);
        vector<tuple<int,int,int>> edges;
        FOR(i,1,m){
            sc3(u,v,w);
            edges.pb(make_tuple(u,v,w));
        }

        VI dist(n,INF);
    	dist[0] = 0;

    	// Relax all edges n-1 times
    	for (int i = 1; i <= n-1; i++) {
    		for (auto e : edges) {
    			tie(u, v, w) = e;
    			dist[v] = min(dist[v], dist[u]+w);
    		}
            /*printf("%d:",i);
            FOR(i,0,n-1) printf("%d,",dist[i]);
            printf("\n");*/
    	}

    	// check negative cycle with one more relaxation
    	for (auto e : edges) {
            tie(u, v, w) = e;
            int temp = dist[v];
            dist[v] = min(dist[v], dist[u]+w);
    		if (temp != INF && dist[v] < temp){
    			neg = true;
                break;
    		}
    	}
        //FOR(i,0,n-1) printf("%d,",dist[i]);
        //printf("\n");

    	if(neg) printf("possible\n");
        else printf("not possible\n");

    }

	return 0;
}
