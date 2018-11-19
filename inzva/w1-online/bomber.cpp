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
   int r,c,n; sc3(r,c,n);
   vector<string> grid;
   char row[205];

   FOR(i, 1, r)
   {
      scs(row);
      grid.emb(row);
   }
   
   bool all = true;
   FOR(i,0,r-1){
      FOR(j,0,c-1){
         if(grid[i][j] != '.'){
            all = false;
            break;
         }
      }
   }
   if(all){
      int st = n%3 ;
      if(st == 1){
         FOR(i,1,r){
            FOR(j,1,c){
               printf(".");
            }
            printf("\n");
         }
      }
      else{
         FOR(i,1,r){
            FOR(j,1,c){
               printf("O");
            }
            printf("\n");
         }
      }
      return 0;
   }


   if(n==1){
      FOR(i,0,r-1){
         FOR(j,0,c-1){
            printf("%c", grid[i][j]);
         }
         printf("\n");
      }
      return 0;
   }

   if(n==2 || n==4){
      FOR(i,1,r){
         FOR(j,1,c){
            printf("O");
         }
         printf("\n");
      }
      return 0;
   }



   char st3[r][c];
   FOR(i,0,r-1){
      FOR(j,0,c-1){
         st3[i][j] = 'x';
      }
   }
   FOR(i,0,r-1){
      FOR(j,0,c-1){
            if(grid[i][j] == 'O'){
               st3[i][j] = '.';
               if(i-1>=0) st3[i-1][j]='.';
               if(i+1<r) st3[i+1][j] ='.';
               if(j-1 >= 0) st3[i][j-1] = '.';
               if(j+1 < c) st3[i][j+1] = '.';
            }
            else if(st3[i][j] == 'x'){
               st3[i][j] = 'O';
            }
      }
   }
   bool triple = true;
   FOR(i,0,r-1){
      FOR(j,0,c-1){
         if(st3[i][j] != '.'){
            triple = false;
            break;
         }
      }
   }

   if(triple){
      int st = n%3 ;
      if(st == 0){
         FOR(i,1,r){
            FOR(j,1,c){
               printf(".");
            }
            printf("\n");
         }
      }
      else{
         FOR(i,1,r){
            FOR(j,1,c){
               printf("O");
            }
            printf("\n");
         }
      }
      return 0;
   }


   int st = n%4 ;
   //cout << st << endl;
   if(st == 0 || st == 2){
      FOR(i,1,r){
         FOR(j,1,c){
            printf("O");
         }
         printf("\n");
      }
   }
   else if(st == 1){
      FOR(i,0,r-1){
         FOR(j,0,c-1){
            printf("%c", grid[i][j]);
         }
         printf("\n");
      }
   }
   else{ //st=3

      FOR(i,0,r-1){
         FOR(j,0,c-1){
            printf("%c", st3[i][j]);
         }
         printf("\n");
      }
   }





	return 0;
}
