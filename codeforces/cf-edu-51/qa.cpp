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

int main() {
   int t; sc(t);
   char s[110];
   FOR(i, 1, t){
      scs(s);
      int u =0, l= 0, d=0;
      int n = strlen(s);
      FOR(j, 0, n-1){
         if(s[j]>='A' && s[j]<='Z') u++;
         else if(s[j]>='a' && s[j]<='z') l++;
         else if(s[j]>='0' && s[j]<='9') d++;
      }
      if(u && l && d){
         printf("%s\n", s);
         continue;
      }

      if(u == 0 && l == 0){
         s[0] ='A'; s[1] = 'a';
         printf("%s\n", s);
         continue;
      }
      if(u == 0 && d == 0){
         s[0] ='A'; s[1] = '2';
         printf("%s\n", s);
         continue;
      }
      if(d == 0 && l == 0){
         s[0] ='2'; s[1] = 'a';
         printf("%s\n", s);
         continue;
      }

      if(u == 0){
         if(l == 1){
            int j=0;
            while(s[j]>='a' && s[j]<='z') j++;
            s[j] = 'A';
            printf("%s\n", s);
            continue;
         }
         if(d == 1){
            int j=0;
            while(s[j]>='0' && s[j]<='9') j++;
            s[j] = 'A';
            printf("%s\n", s);
            continue;
         }
         s[0] = 'A';
         printf("%s\n", s);
         continue;
      }

      if(l == 0){
         if(u == 1){
            int j=0;
            while(s[j]>='A' && s[j]<='Z') j++;
            s[j] = 'a';
            printf("%s\n", s);
            continue;
         }
         if(d == 1){
            int j=0;
            while(s[j]>='0' && s[j]<='9') j++;
            s[j] = 'a';
            printf("%s\n", s);
            continue;
         }
         s[0] = 'a';
         printf("%s\n", s);
         continue;
      }

      if(d == 0){
         if(u == 1){
            int j=0;
            while(s[j]>='A' && s[j]<='Z') j++;
            s[j] = '2';
            printf("%s\n", s);
            continue;
         }
         if(l == 1){
            int j=0;
            while(s[j]>='a' && s[j]<='z') j++;
            s[j] = '2';
            printf("%s\n", s);
            continue;
         }
         s[0] = '2';
         printf("%s\n", s);
         continue;
      }

   }



	return 0;
}
