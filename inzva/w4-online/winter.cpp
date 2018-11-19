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
int l[7];
int n,m;
bool can;
void dfs(int p){
   if(p == n) can = true;
   if(can) return;
   FOR(i,0,2){
      int ws = wants[p][i];
      if(l[ws] == 0) continue;
      l[ws]--;
      dfs(p+1);
      l[ws]++;
   }
}

int main() {
   int t; cin >> t;
   string s;
   while(t--){
      cin >> n >> m;
      FOR(i,0,6){
         l[i] = m/7;
      }
      FOR(i,1,n){
         cin >> s;
         wants[i][0] = getInd(s);
         cin >> s;
         wants[i][1] = getInd(s);
         cin >> s;
         wants[i][2] = getInd(s);
      }
       dfs(1);
      if(can) cout << "YES\n";
      else cout << "NO\n";
   }



	return 0;
}
