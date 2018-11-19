#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>  VI;
typedef pair<int, int>  PII;
typedef pair <ll, ll>  PLL;
typedef vector<pair<int, int>>  VPII;

using namespace std;

#define SC(i) scanf("%d", &(i))
#define SC2(i,j) scanf("%d%d", &(i), &(j))
#define SC3(i,j,k) scanf("%d%d%d", &(i), &(j), &(k))
#define SCL(i) scanf("%lld", &(i))

#define FOR(i,x,y) for(ll i=(ll)(x); i<= (ll)(y); i++)
#define REV(i,x,y) for(ll i=(ll)(x); i>= (ll)(y); i--)

#define MEM(a)		memset(a,0,sizeof(a))
#define MINUS(a)	memset(a,0xff,sizeof(a))

#define PR(i)		cout << i << endl
#define PR2(i,j)	cout << i << " " << j << endl
#define PR3(i,j,k)	cout << i << " " << j << " " << k << endl

#define pb(a) push_back((a))
#define fi first
#define se second

// Driver code
int main()
{
	int n; SC(n);
	int prev = 0;
	int w, h; 
	scanf("%d%d", &w, &h);
	if( w > h) swap(w,h);
	prev = h;
	bool pos = true;
	FOR(i, 1, n-1){
		scanf("%d%d", &w, &h);
		if( w > prev && h> prev ){
			pos = false;
			break;
		}
		if( w > h) swap(w,h);
		if( h > prev ) swap(w,h);
		prev = h;
	}
	if(pos) cout << "YES" << endl;
	else cout << "NO" << endl;

	

	return 0;
}

