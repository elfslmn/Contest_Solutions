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


int main() {
	int n,m ; sc2(n,m);
	vector<VI> c(m, VI(n,0));

	FOR(i,0,m-1){
		FOR(j, 0, n-1){
			sc(c[i][j]);
		}
	}
   vector<VI> mat(m+1, VI(n+1,0));

   REV(j, n-1, 0){
      REV(i, m-1, 0){
         if(i == m-1) mat[i][j] = mat[i][j+1]+c[i][j];
         else mat[i][j] = min(mat[i][j+1]+c[i][j], mat[i+1][j]);
         //printf("(%d,%d) = %d\n",i,j,mat[i][j]);
      }
   }
   /*FOR(i,0,m-1){
		FOR(j, 0, n-1){
			printf("%d ",mat[i][j]);
		}
      printf("\n");
	}*/
   PR(mat[0][0]);
	return 0;
}
