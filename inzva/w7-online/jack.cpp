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

#define sc(n)        scanf("%d",&n)
#define sc2(i,j)    scanf("%d%d",&i,&j)
#define sc3(i,j,k)    scanf("%d%d%d",&i,&j,&k)
#define scl(n)         scanf("%lld",&n)
#define scf(n)         scanf("%lf",&n)
#define scs(n)      scanf("%s",n)

#define FOR(i,x,y)     for(int i=(x); i<=(y); i++)
#define REV(i,x,y)     for(int i=(x); i>=(y); i--)

#define MEM(a)        memset(a,0,sizeof(a))
#define MINUS(a)    memset(a,0xff,sizeof(a))
#define MINF(a)        memset(a,0x3f,sizeof(a))

#define PR(i)        printf("%d\n", (i))
#define PRL(i)        printf("%lld\n", (i))
#define PRF(i)        printf("%.10f\n", (i))

#define DBG2(i,j)    cout << i << " " << j << endl
#define DBG3(i,j,k)    cout << i << " " << j << " " << k << endl
#define DBGA(arr)     FOR(i,0,(arr.size()-1)){ cout << arr[i] << " ";} cout << "\n"

#define pb push_back
#define fi first
#define se second
// not for long
#define infi 0x3f3f3f3f
#define infd (double)(1.0)/(0.0)


int main() {
    int n,m; sc2(n,m);
    VPII adj[n+1];
    int u,v,w;
    FOR(i,1,m){
        sc3(u,v,w);
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    VI dist(n+1, INT_MAX);
    vector<bool> proc(n+1, false);
    dist[1] = 0;
    priority_queue<PII> q;
    q.push({0,1});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (proc[a]) continue;
        proc[a] = true;    // at this point dist[a] has minimum value and wont change anymore
        if(a == n) break;

        for (auto u : adj[a]) {
            int b = u.first, w = u.second;

            if (max(dist[a],w) < dist[b]) {
                dist[b] = max(dist[a],w);
                q.push({-dist[b],b});
            }
        }
    }
    if(dist[n] == INT_MAX) printf("NO PATH EXISTS\n");
    else PR(dist[n]);

    return 0;
}
