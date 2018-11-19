// g++ -std=c++14 -O2 -Wall
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

struct pair_hash
{
   size_t operator()(const pair<int,int>&x)const{
      size_t seed = 0;
      std::hash<int> hasher;
      seed ^= hasher(x.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      seed ^= hasher(x.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      return seed;
   }
};

int main() {
   int n; sc(n);
   unordered_set<PII, pair_hash> set;
   int ax, ay, bx, by;
   int xdiff, ydiff;
   int xdir, ydir;
   FOR(i, 1,n){
      sc2(ax,ay);
      sc2(bx,by);
      xdiff = abs(ax-bx);
      ydiff = abs(ay-by);
      xdir = ax>bx ? 1:-1;
      ydir = ay>by ? 1:-1;

      //printf("-----------bef size: %d\n", set.size());
      //printf("diffs: %d %d\n", xdiff, ydiff);
      //printf("dirs: %d %d\n", xdir, ydir);


      if(xdiff == 0){
         FOR(i, 0, ydiff){
            set.insert({bx, by+i*ydir});
         }
         continue;
      }
      if(ydiff == 0){
         FOR(i, 0, xdiff){
            set.insert({bx+i*xdir, by});
         }
         continue;
      }

      if(xdiff == ydiff){
         FOR(i,0,xdiff){
            set.insert({bx+i*xdir, by+i*ydir});
         }
         continue;
      }
      set.insert({ax,ay});
      set.insert({bx,by});
      int s = __gcd(xdiff, ydiff);
      //printf("gcd: %d\n",s);
      if(s == 1){
         continue;
      }
      int xinc= xdiff/s;
      int yinc= ydiff/s;
      FOR(j,1,s-1){
         set.insert({bx+xinc*xdir*j,by + yinc*ydir*j});
      }

   }
   cout << set.size() << endl;

	return 0;
}
