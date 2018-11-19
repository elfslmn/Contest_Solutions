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

int c[110];

int main() {
   int n, s; sc(n);
   int a[n];
   int min = 110, max = 0;
   FOR(i, 0, n-1){
      sc(s);
      a[i] = s;
      c[s]++;
      if(s>max) max =s;
      if(s<min) min = s;
   }
   int nice = 0;
   FOR(i, min, max){
      if(c[i] == 1) nice++;
   }

   if(nice == 0){
      printf("YES\n");
      FOR(i, 1, n){
         printf("A");
      }
      printf("\n");
      return 0;
   }

   if(nice%2 == 1){
      //printf("NO\n");
      int odd = -1;
      FOR(i, min, max){
         if(c[i] > 2){
            odd = i;
            break;
         }
      }
      if(odd == -1) {
         printf("NO\n");
      }
      else{
         printf("YES\n");
         int na = 0;
         char set[n+3];
         char ch = 'A';
         VI inds;
         FOR(i, 0, n-1){
            if(na == nice/2) ch = 'B';
            set[i] = ch;
            if(c[a[i]] == 1) na++;
            if(a[i] == odd) inds.push_back(i);
         }
         set[inds[0]] = 'A';
         FOR(i, 1, inds.size()-1){
            set[inds[i]] = 'B';
         }
         set[n] = '\0';

         printf("%s\n",set);

      }

   }
   else{
      printf("YES\n");
      int na = 0;
      char set ='A';
      FOR(i, 0, n-1){
         if(c[a[i]] == 1) {
            printf("%c", set);
            na++;
         }
         else{
            printf("A");
         }
         if(na == nice/2) set = 'B';
      }
      printf("\n");
   }



	return 0;
}
