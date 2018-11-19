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
	ll sum = 0;
	
	bool even = false;
	if(n%2 == 0) even =true;
	
	FOR(i, 0, m-1){
		int x; SC(x);
		int d; SC(d);
		sum += ((ll)n*(ll)x);
		if(d>0){
			sum += ((ll)n*((ll)n-1)/2*(ll)d);
		}
		else{
			if(even){
				int sub = n/2;
				sum += ((ll)sub*((ll)sub+1)/2 + (ll)sub*((ll)sub-1)/2)*(ll)d;
			}
			else{
				int sub = n/2;
				sum += (ll)sub*((ll)sub+1)*(ll)d;
			}
		}
	}
	cout << (double)sum/n <<endl;


	return 0;
}


