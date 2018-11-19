//1042D - Petya and Array
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

#define NMAX 200000
int ar[NMAX*5];  // original array
ll stp[NMAX*5];  // segment tree
ll stn[NMAX*5];
ll t;

//ind : current processed index in segment tree
//i : updated index in the original array
//val : update value
// bas, son : segmentin bası ve sonu

int updatepos(int ind, int bas, int son,int i, int val){
    // i is not in the segment
	if (i < bas || i > son) return stp[ind];

	// at leaf
	if( i==bas && i==son){
        stp[ind] = val;
        return stp[ind];
    }

	// i is in segment, update child segments
	int orta = (bas+son)/2;
	int sol = updatepos(ind*2, bas, orta, i, val);
	int sag = updatepos(ind*2+1, orta+1, son, i, val);

    stp[ind] = (sol + sag);
	return stp[ind];
}

int updateneg(int ind, int bas, int son,int i, int val){
    // i is not in the segment
	if (i < bas || i > son) return stn[ind];

	// at leaf
	if( i==bas && i==son){
        stn[ind] = val;
        return stn[ind];
    }

	// i is in segment, update child segments
	int orta = (bas+son)/2;
	int sol = updateneg(ind*2, bas, orta, i, val);
	int sag = updateneg(ind*2+1, orta+1, son, i, val);

    stn[ind] = (sol + sag);
	return stn[ind];
}

//ind : current processed index in segment tree
// bas, son : segmentin bası ve sonu
// a,b : istenen rangein bası ve sonu

ll query(int ind, int bas, int son,int a, int b){
	 // segment is outside of range[a,b] 	( bas son a b  ||  a b bas son )
	if (son < a || b < bas || bas > son)  return 0;

	// segment is inside of given range  ( a bas son b )
	if (a <= bas && son <= b){
      if(stp[ind]< t) {
         ll res = (ll)(son-bas)*(son-bas+1)/2;
         return res;
      }
   }
   int c = stp[ind]+stn[ind]<t ? 1:0 ;
	// some part of segment is inside given range
	int orta = (bas+son)/2;
	ll sol = query(ind*2, bas, orta, a,b);
	ll sag= query(ind*2+1, orta+1, son, a,b);

	return sol + sag +c;
}

int nextPowerOf2(int n){
    int count = 0;
    if (n && !(n & (n - 1)))
        return n;
    while( n != 0){
        n >>= 1;
        count += 1;
    }
    return 1 << count;
}

int main() {
   int n; sc(n);
   scl(t);
   int c;
   int np = nextPowerOf2(n);
   for(int i=1; i<=n; i++){
      sc(c);
      if(c>0) updatepos(1,1,np,i,c);
      else if(c<0) updateneg(1,1,np,i,c);
   }
   PRL(query(0,1,np,1,n));

	return 0;
}
