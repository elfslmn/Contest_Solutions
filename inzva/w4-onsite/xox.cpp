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
PII dots;

char whowin(){
   if(dots.size() == 0) return 'D';

   FOR(i,0,2){
      if(gr[i][0] == gr[i][1] && gr[i][1]== gr[i][2]){
         return gr[i][0];
      }
   }
   FOR(i,0,2){
      if(gr[0][i] == gr[1][i] && gr[1][i]== gr[2][i]){
         return gr[0][i];
      }
   }

   else return 'N';
}

void solve(int r, int c, int turn){ // 0:o 1:x
   if(r == 3 || c == 3) return;
   if(gr[r][c] != '.'){
      solve(r+1, c, turn);
      solve(r, c+1, turn);
      return;
   }

   if(turn == 0){
      gr[r][c] = 'O';
      char res = whowin();
      if(res == 'O'){
          o++;
          return;
      }
      else if (res == 'N' || res == '.'){
         solve(r+1, c, 1);
         solve(r, c+1, 1);
      }
      else if(res == 'D'){
         d++;
         return;
      }
      gr[r][c] = '.';
   }
   else{
      gr[r][c] = 'X';
      char res = whowin();
      if(res == 'X'){
         x++;
         return;
      }
      else if (res == 'N' || res == '.'){
         solve(r+1, c, 0);
         solve(r, c+1, 0);
      }
      else if(res == 'D'){
         d++;
         return;
      }
      gr[r][c] = '.';
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
   solve(0,0,0);
   printf("X wins: %d\n",x);
   printf("O wins: %d\n",o);
   printf("Draw: %d\n",d);





	return 0;
}
