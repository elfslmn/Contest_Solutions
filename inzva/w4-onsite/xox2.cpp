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

char gr[3][3];
int x, o, d;
VPII dots;
int used[9];

bool whowin(){
   FOR(i,0,2){
      if(gr[i][0] == gr[i][1] && gr[i][1]== gr[i][2]){
         if(gr[i][0] == 'X')x++;
         else if(gr[i][0] == 'O') o++;
         else return false;
         return true;
      }
   }
   FOR(i,0,2){
      if(gr[0][i] == gr[1][i] && gr[1][i]== gr[2][i]){
         if(gr[0][i] == 'X')x++;
         else if(gr[0][i] == 'O') o++;
         else return false;
         return true;
      }
   }
   FOR(i,0,2){
      FOR(j,0,2){
         if(gr[i][j] == '.') return false;
      }
   }
   d++;
   return true;
}

void solve(int turn){ // 0:o 1:x
   if(turn == 0){
      for(int i= 0; i<dots.size(); i++){
         if(used[i] == 1) continue;
         PII p = dots[i];
         gr[p.fi][p.se] = 'O';
         used[i] = 1;
         if(!whowin()){
            solve(1);
         }
         gr[p.fi][p.se] = '.';
         used[i] = -1;
      }
   }
   else{
      for(int i= 0; i<dots.size(); i++){
         if(used[i] == 1) continue;
         PII p = dots[i];
         gr[p.fi][p.se] = 'X';
         used[i] = 1;
         if(!whowin()){
            solve(0);
         }
         gr[p.fi][p.se] = '.';
         used[i] = -1;
      }
   }

}


int main() {
   FOR(i,0,2){
      string l;
      getline(cin,l);
      auto arr = l.c_str();
      gr[i][0] = arr[0];
      gr[i][1] = arr[1];
      gr[i][2] = arr[2];
      if(arr[0] == '.') dots.pb({i,0});
      if(arr[1] == '.') dots.pb({i,1});
      if(arr[2] == '.') dots.pb({i,2});
   }
   for(int i= 0; i<dots.size(); i++){
      used[i] = -1;
   }
   solve(0);
   printf("X wins: %d\n",x);
   printf("O wins: %d\n",o);
   printf("Draw: %d\n",d);





	return 0;
}
