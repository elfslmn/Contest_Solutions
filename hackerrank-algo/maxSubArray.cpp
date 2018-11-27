// https://www.hackerrank.com/challenges/maxsubarray/problem
// Not efficeient O(n^2) solution
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

int main() {
   int t; sc(t);
   int n;
   while(t--){
      sc(n);
      int arr[n+1];
      int sa[n+1];
      ll sum2 = 0;
      ll maxNeg = -100000;
      sa[0] = 0;
      FOR(i,1,n){
         sc(arr[i]);
         if(arr[i]>0) sum2+= arr[i];
         else{
            if(arr[i]> maxNeg) maxNeg = arr[i];
         }
         sa[i] = sa[i-1]+arr[i];
      }
      if(sum2 == 0){
         printf("%lld %lld\n", maxNeg, maxNeg);
         continue;
      }

      ll sum1 = sa[n] - sum2 -100;
      ll sub;
      FOR(s,1,n){
         FOR(e,s,n){
            sub = sa[e]-sa[s-1];
            if(sub > sum1) sum1 = sub;
         }
      }
      printf("%lld %lld\n", sum1, sum2);

   }

	return 0;
}
