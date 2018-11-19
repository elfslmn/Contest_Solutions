// g++ -std=c++14 -O2 -Wall qa.cpp
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
#define scc(n)  	scanf("%c",&n)

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
   int n; sc(n);
   int p;
   int nmax = 300001;
   int vits[7];
   FOR(i, 0, 6){
      vits[i] = nmax;
   }

   FOR(i ,0, n-1){
      string v;
      cin >> p >> v ;
      bool a = false, b = false, c = false;
      int count = v.size();
      FOR(j,0,count-1){
         //cout <<v[j];
         if(v[j] == 'A'){
            a = true;
         }
         if(v[j] == 'B'){
            b = true;
         }
         if(v[j] == 'C'){
            c = true;
         }
      }
      //cout << count << endl;
      if(count == 3 && p < vits[6]){
         vits[6] = p;
      }
      else if(count == 2){
         if(a && b && p < vits[3]){
            vits[3] = p;
         }
         else if(a && c && p < vits[4]){
            vits[4] = p;
         }
         else if(c && b && p < vits[5]){
            vits[5] = p;
         }
      }
      else if(count == 1){
         if(a && p < vits[0]){
            vits[0] = p;
         }
         if(b && p < vits[1]){
            vits[1] = p;
         }
         if(c && p < vits[2]){
            vits[2] = p;
         }
      }
   }

   int res = vits[6];
   if((vits[0]+ vits[1]+ vits[2])< res) res = (vits[0]+ vits[1]+ vits[2]);
   if((vits[3]+ vits[4]) < res) res = (vits[3]+ vits[4]);
   if((vits[3]+ vits[5]) < res) res = (vits[3]+ vits[5]);
   if((vits[5]+ vits[4]) < res) res = (vits[5]+ vits[4]);
   if((vits[0]+ vits[5]) < res) res = (vits[0]+ vits[5]);
   if((vits[1]+ vits[4]) < res) res = (vits[1]+ vits[4]);
   if((vits[3]+ vits[2]) < res) res = (vits[3]+ vits[2]);
   if(res == nmax) PR(-1);
   else PR(res);


	return 0;
}
