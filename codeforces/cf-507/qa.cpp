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

int main() {
   int n, a,b; sc3(n,a,b);

   int ar[n+1];
   FOR(i, 1, n){
      int c; sc(c);
      ar[i] = c;
   }
   int sum =0;
   FOR(i, 1, n/2){
      if(ar[i] != ar[n-i+1]){
         if(ar[i] == 2){
            if(ar[n-i+1] == 0) sum+=a;
            else if(ar[n-i+1] == 1) sum+=b;
         }
         else if(ar[n-i+1] == 2){
            if(ar[i] == 0) sum+=a;
            else if(ar[i] == 1) sum+=b;
         }
         else{
            cout << -1 << endl;
            return 0;
         }
      }
      else{
         if(ar[i] == 2){
            if(a>b) sum+=(2*b);
            else sum+=(2*a);
         }
      }
   }
   if(n%2 == 1 && ar[n/2+1] == 2){
      if(a>b) sum+=b;
      else sum+=a;
   }
   cout << sum << endl;


	return 0;
}
