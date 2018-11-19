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
#define DBGA(arr) 	FOR(i,0,(arr.size()-1)){ cout << arr[i] << " ";} cout << "\n";

#define emb emplace_back
#define em emplace
#define fi first
#define se second
// not for long
#define infi 0x3f3f3f3f
#define infd (double)(1.0)/(0.0);


int main() {
   int m, n, r; sc3(m,n,r);
   ll ar[m][n];
   ll x;
   FOR(i,0, m-1){
      FOR(j, 0, n-1){
         scl(x);
         ar[i][j] = x;
      }
   }

   int kat = min((m+1)/2, (n+1)/2);
   vector<vector<ll> > circs;
   FOR(k , 0, kat-1){
      PII cur = {k,k};
      vector<ll> c;
      do{
         c.emb(ar[cur.fi][cur.se]);
         if(cur.fi == k){
            if(cur.se == n-1-k){
               cur.fi++;
            }
            else{
               cur.se++;
            }
            continue;
         }

         if(cur.fi == m-1-k){
            if(cur.se == k){
               cur.fi--;
            }
            else{
               cur.se--;
            }
            continue;
         }

         if(cur.se == k){
            if(cur.fi == k){
               cur.se++;
            }
            else{
               cur.fi--;
            }
            continue;
         }

         if(cur.se == n-1-k){
            if(cur.fi == m-1-k){
               cur.se--;
            }
            else{
               cur.fi++;
            }
            continue;
         }

      }while(cur != make_pair(k,k));
      circs.emb(c);
   }

   FOR(i, 0, circs.size()-1){
      int rot = r%circs[i].size();
      //DBG2(i, rot);
      rotate(circs[i].begin(),circs[i].begin()+rot,circs[i].end());
      /*FOR(j, 0, circs[i].size()-1){
         printf("%lld ", circs[i][j]);
      }
      printf("\n"); */
   }

   FOR(k , 0, kat-1){
      PII cur = {k,k};
      int i = 0;
      do{
         ar[cur.fi][cur.se] = circs[k][i];
         i++;
         if(cur.fi == k){
            if(cur.se == n-1-k){
               cur.fi++;
            }
            else{
               cur.se++;
            }
            continue;
         }

         if(cur.fi == m-1-k){
            if(cur.se == k){
               cur.fi--;
            }
            else{
               cur.se--;
            }
            continue;
         }

         if(cur.se == k){
            if(cur.fi == k){
               cur.se++;
            }
            else{
               cur.fi--;
            }
            continue;
         }

         if(cur.se == n-1-k){
            if(cur.fi == m-1-k){
               cur.se--;
            }
            else{
               cur.fi++;
            }
            continue;
         }

      }while(cur != make_pair(k,k));

   }

   FOR(i,0, m-1){
      FOR(j, 0, n-1){
         printf("%lld ", ar[i][j]);
      }
      printf("\n");
   }




	return 0;
}
