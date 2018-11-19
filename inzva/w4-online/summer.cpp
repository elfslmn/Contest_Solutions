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
   char s,f;
   int fc,fr;
   int sr,sc;

   FOR(i,1,n){
      scanf(" %c%d %c%d",&s,&sr,&f,&fr);
      //printf("DBG, %c%d %c%d\n", s,sr,f,fr);
      sc = (int)s -96;
      fc = (int)f -96;
      //printf("DBG, %d%d %d%d\n", sc,sr,fc,fr);
      bool vis[9][9];
      int dist[9][9];
      FOR(ix,0,8){
         FOR(iy,0,8){
            vis[ix][iy]=false;
            dist[ix][iy]=0;
         }
      }
      queue<PII> q;

      int nc,nr;
   	vis[sc][sr]= true;
   	dist[sc][sr] = 0; 	// distance to the started node

   	q.push({sc,sr});
   	while (!q.empty()) {
   		PII cur = q.front(); q.pop();
   		// process node s
   		if(cur.fi == fc && cur.se == fr) break;
         //DBG2(cur.fi,cur.se);
         FOR(ic, -2, 2){
            if(ic == 0) continue;
            FOR(ir, -2, 2){
               //DBG2(ic,ir);
               if(ir == 0) continue;
               if((ic==1 || ic==-1) && (ir==-1 || ir==1)) continue;
               if((ic==2 || ic==-2) && (ir==-2 || ir==2)) continue;
               //cout <<"pass" <<endl;
               nc = cur.fi+ic; nr=cur.se+ir;
               if(nc<1|| nc>8 || nr<1 || nr>8) continue;
               if(vis[nc][nr]) continue;
               vis[nc][nr] = true;
               dist[nc][nr] = dist[cur.fi][cur.se]+1;
               q.push({nc,nr});
            }
         }
   	}
      printf("To get from %c%d to %c%d takes %d knight moves.\n", s,sr,f,fr, dist[fc][fr]);

   }



	return 0;
}
