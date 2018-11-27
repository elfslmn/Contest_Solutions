// https://www.hackerrank.com/challenges/maxsubarray/problem
//efficeient O(nlogn) solution - divide and conquer
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

#define intmin -2000000000
int arr[100005];

ll crossSum(int s, int m, int e){
   ll leftmax = intmin;
   ll sum = 0;
   REV(i,m,s){
      sum += arr[i];
      if(sum > leftmax) leftmax = sum;
   }

   ll rightMax = intmin;
   sum = 0;
   FOR(i,m+1, e){
      sum += arr[i];
      if(sum > rightMax) rightMax = sum;
   }
   return (leftmax + rightMax);
}

ll solve(int s, int e){
   if(s == e) return arr[s];
   int m = (s+e)/2;
   ll res = max(solve(s,m), solve(m+1, e));
   return max(res, crossSum(s,m,e));
}

int main() {
   int t; sc(t);
   int n;
   while(t--){
      sc(n);
      ll sum2 = 0;
      ll maxNeg = intmin;
      FOR(i,0,n-1){
         sc(arr[i]);
         if(arr[i]>0) sum2+= arr[i];
         else{
            if(arr[i]> maxNeg) maxNeg = arr[i];
         }
      }
      if(sum2 == 0){
         printf("%lld %lld\n", maxNeg, maxNeg);
         continue;
      }
      ll res = solve(0,n-1);
      printf("%lld %lld\n",res, sum2);
   }

	return 0;
}
