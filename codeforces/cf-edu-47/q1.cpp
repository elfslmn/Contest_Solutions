// g++ -std=c++11 -O2 -Wall
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>  VI;
typedef pair<int, int>  PII;
typedef pair <ll, ll>  PLL;
typedef vector<pair<int, int>>  VPII;



#define SC(i) scanf("%d", &(i))
#define SC2(i,j) scanf("%d%d", &(i), &(j))
#define SC3(i,j,k) scanf("%d%d%d", &(i), &(j), &(k))

#define FOR(i,x,y) for(ll i=(ll)(x); i<= (ll)(y); i++)
#define REV(i,x,y) for(ll i=(ll)(x); i>= (ll)(y); i--)

#define MEM(a)		memset(a,0,sizeof(a))
#define MINUS(a)	memset(a,0xff,sizeof(a))

#define PR(i)		printf("%d\n", (i))
#define PR2(i,j)	cout << i << " " << j << endl
#define PR3(i,j,k)	cout << i << " " << j << " " << k << endl

#define pb(a) push_back((a))
#define fi first
#define se second


int main() {
	int n; SC(n);
	int m; SC(m); 
	
	int c[n];
	
	FOR(i, 0, n-1){
		int x; SC(x);
		c[i] = x;
	}
	
	int res = 0;
	int a; SC(a);
	m--;
	FOR(i, 0, n-1){
		if( a >= c[i]){
			res++;
			if(m==0) break;
			SC(a);
			m--;
		}
	}

	PR(res);

	return 0;
}


