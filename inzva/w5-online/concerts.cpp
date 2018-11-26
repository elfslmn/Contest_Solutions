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

int mat[305][100005];
#define mod 1000000007

int main() {
   int k, n; sc2(k,n);
   int h[26];
   FOR(i,0,25){
      sc(h[i]);
   }
   string s,t;
   getline(cin, t);
   getline(cin, t);
   t = std::regex_replace(t, std::regex("^ +| +$|( ) +"), "$1");
   getline(cin, s);
   s = std::regex_replace(s, std::regex("^ +| +$|( ) +"), "$1");



   for (int i = 1; i <= k; i++)
      mat[i][0] = 0;

   for (int j = 0; j <= n; j++)
      mat[0][j] = 1;

   // First conecrt dont have to wait previous h constraint.
   FOR(j,1,n){
      if(t[0] != s[j-1]){
         mat[1][j] = mat[1][j-1];
      }
      else{
         mat[1][j] = (mat[1][j-1]+mat[0][j-1])%mod;
      }
   }

   FOR(i,2,k){
      FOR(j,1,n){
         if(t[i-1] != s[j-1]){
            mat[i][j] = mat[i][j-1];
         }
         else{
            mat[i][j] = mat[i][j-1];
            if(j-1-h[t[i-2] -'A'] >= 0){
               mat[i][j] += mat[i-1][j-1-h[t[i-2] -'A']];
               mat[i][j] %= mod; 
            }
         }
      }
   }
   PR(mat[k][n]);

   return 0;
}
