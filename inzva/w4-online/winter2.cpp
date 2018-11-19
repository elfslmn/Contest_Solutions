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

/* Try
1
3 7
S M L
S M L
S M L
*/

int getInd(string s){
      if(s == "XXS") return 0;
      if(s == "XS") return 1;
      if(s == "S") return 2;
      if(s == "M") return 3;
      if(s == "L") return 4;
      if(s == "XL") return 5;
      if(s == "XXL") return 6;
   return -1;
}
int wants[25][3];
USI sizes[7];

PII getMinWanted(){
   int m = 10;
   int ind = -1;
   FOR(i,0,6){
      if(sizes[i].size()>0 && sizes[i].size()<m){
         m = sizes[i].size();
         ind = i;
      }
   }
   return {ind, m};
}

int main() {
   int t; cin >> t;
   string s;
   int sz , n, m;
   while(t--){
      cin >> n >> m;
      FOR(i,1,n){
         FOR(j,0,2){
            cin >> s;
            sz = getInd(s);
            wants[i][j] = sz;
            sizes[sz].emplace(i);
         }
      }
      while(n>0){
         PII sz = getMinWanted();
         if(sz.se > m/7){
            printf("Cannot share sz %d among %d people\n", sz.fi,sz.se);
            //printf("NO\n");
            //break;
         }
         // give tshirst
         for(auto p : sizes[sz.fi]){
            printf("Size %d is given to people %d\n", sz.fi,p);
            FOR(i,0,2){
               if(wants[p][i] == sz.fi) continue;
               sizes[wants[p][i]].erase(p); // silmiyor neden???
            }
            n--;
         }
         sizes[sz.fi].clear();

         /*cout << "Remaining wants\n";
         FOR(i,0,6){
            printf("Sz %d wants by %d people\n", i,sizes[i].size());
         }*/
      }
      if(n <= 0) printf("YES\n");

      MEM(wants);
      FOR(i,0,6){
         sizes[i].clear();
      }

   }



	return 0;
}
