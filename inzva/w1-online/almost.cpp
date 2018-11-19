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
   int n; sc(n);
   int arr[n+2]; arr[0] = -1; arr[n+1] = 1000005;
   int x;
   FOR(i, 1, n){
      sc(x);
      arr[i] = x;
   }
   int li = -1, ri = -1;

   VPII parts;
   FOR(i, 2, n){
      if(arr[i] < arr[i-1] && li < 0){ // beginning of decend
         li = i-1;
      }
      if(arr[i] > arr[i-1] && li > 0){ // end of decend
         ri = i-1;
         parts.push_back({li, ri});
         li = -1; ri = -1;
      }
   }

   if(li > 0 && ri < 0) // decend begin but not end
   {
      ri = n;
      parts.push_back({li, ri});
   }

   if(parts.size() == 0){ // already sorted
      printf("yes\n");
      return 0;
   }

   if(parts.size() == 1){
      li = parts[0].fi;
      ri = parts[0].se;
      if(ri -li > 1){ // reverse
         if(arr[li]<arr[ri+1] && arr[ri]>arr[li-1]){
            printf("yes\n");
            printf("reverse %d %d\n",li, ri);
            return 0;
         }
         else{
            printf("no\n");
            return 0;
         }
      }
      if(ri - li == 1){ // swap
         if(arr[li]<arr[ri+1] && arr[ri]>arr[li-1]){
            printf("yes\n");
            printf("swap %d %d\n",li, ri);
            return 0;
         }
         else{
            printf("no\n");
            return 0;
         }
      }
   }

   if(parts.size() == 2){
      li = parts[0].fi;
      ri = parts[1].se;
      if(arr[ri-1]<arr[li] && arr[li]<arr[ri+1] && arr[ri]<arr[li+1] && arr[ri]>arr[li-1]){
         printf("yes\n");
         printf("swap %d %d\n",li, ri);
         return 0;
      }
      else{
         printf("no\n");
         return 0;
      }
   }
   printf("no\n");
	return 0;
}
