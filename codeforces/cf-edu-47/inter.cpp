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
int m = 998244353;

int main() {
	int n; SC(n);
	ll c[n+1];
	c[1] = 1;
	FOR(i, 2, n){
		c[i] = (c[i-1]*2)%m + (ll)pow(2,i-2)%m;
	}
	ll sum = 0;
	FOR(i, 0, n-1){
		int a; SC(a);
		sum += (ll)a*c[n-i];
		sum = (sum%m);
	}
	cout << sum << endl;


	return 0;
}


