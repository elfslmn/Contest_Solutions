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
   int n, k; sc2(n,k);
   string s;
   if(n==1){
      printf("1 1\n");
      getline(cin ,s);
      return 0;
   }
   int ml=1;
   int mr=n;
   int mid = (ml+mr)/2;
   printf("%d %d\n", ml, mid);
   fflush(stdout);
   while(1){
      getline(cin ,s);
      if(s == "Yes"){
         if(ml == mid){
            return 0;
         }
         mr = mid;
         ml -=k;
         if(ml<1) ml=1;
         mr +=k;
         if(mr>n) mr = n;
         mid = (ml+mr)/2;
         printf("%d %d\n", ml, mid);
         fflush(stdout);
      }
      else if(s == "No"){
         ml = mid+1;
         ml -=k;
         if(ml<1) ml=1;
         mr +=k;
         if(mr>n) mr = n;
         mid = (ml+mr)/2;
         printf("%d %d\n", ml, mid);
         fflush(stdout);
      }
      else if(s == "Bad"){
         	return 0;
      }
      DBG3(ml, mid, mr);
   }

	return 0;
}
