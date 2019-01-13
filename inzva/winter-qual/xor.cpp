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

// SUM OF A RANGE ( update single value)
// if you update a range, use lazy version

int ar[500005];  // original array
int st[500005];  // segment tree

//ind : current processed index in segment tree
//i : updated index in the original array
//val : update value
// bas, son : segmentin basi ve sonu

int update(int ind, int bas, int son,int i, int val){
    // i is not in the segment
	if (i < bas || i > son) return st[ind];

	// at leaf
	if( i==bas && i==son){
        st[ind] = val;
        return st[ind];
    }

	// i is in segment, update child segments
	int orta = (bas+son)/2;
	int sol = update(ind*2, bas, orta, i, val);
	int sag = update(ind*2+1, orta+1, son, i, val);

    st[ind] = sol ^ sag;
	return st[ind];
}

//ind : current processed index in segment tree
// bas, son : segmentin basi ve sonu
// a,b : istenen rangein basi ve sonu

int query(int ind, int bas, int son,int a, int b){
	 // segment is outside of range[a,b] 	( bas son a b  ||  a b bas son )
	if (son < a || b < bas || bas > son)  return 0;

	// segment is inside of given range  ( a bas son b )
	if (a <= bas && son <= b) return st[ind];

	// some part of segment is inside given range
	int orta = (bas+son)/2;
	int sol = query(ind*2, bas, orta, a,b);
	int sag= query(ind*2+1, orta+1, son, a,b);

	return sol ^ sag ;
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


int main(){
 	// read input and keep in ar[]
    int n, q; sc2(n,q);
    FOR(i,1,n){
        sc(ar[i]);
    }

 	int np = nextPowerOf2(n);
 	// fill segment tree
	FOR(i,1,n){
		update(1,1,np,i,ar[i]);
	}

    int t,l,r;
    while(q--){
        sc3(t,l,r);
        if( t == 1){
            PR(query(1,1,np,l,r));
        }
        else if(t== 2){
            update(1,1,np,l,r);
        }
    }
    return 0;
}
