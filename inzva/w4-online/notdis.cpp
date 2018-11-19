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

#define nmax 100005

int link[nmax];
int size[nmax];

//find returns the representative for an element x
int find(int x) {
	while (x != link[x]) x = link[x];
	return x;
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (size[a] < size[b]) swap(a,b);
	size[a] += size[b];
	link[b] = a;
}

//checks whether elements a and b belong to the same set
bool same(int a, int b) {
	return find(a) == find(b);
}

int main() {
   int t; sc(t);
   int n,a,b;
   FOR(ti, 1,t){
      sc(n);
      for (int i = 1; i <= n; i++) link[i] = i;
      for (int i = 1; i <= n; i++) size[i] = 1;
      USI p;
      FOR(i,1,n){
         sc2(a,b);
         p.insert(a);
         p.insert(b);
         if (!same(a,b)) unite(a,b);
      }
      USI found;
      int res = 0;
      for(auto x: p){
         if(found.find(x) != found.end()) continue;
         while (x != link[x]){
            found.insert(x);
            x = link[x];
         }
         found.insert(x);
         res += ((size[x]+1)/2);
      }
      printf("Case %d: %d\n", ti,res);
      // TODO not true use bipartite check

   }



	return 0;
}
