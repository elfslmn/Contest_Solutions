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
	
	map<int, int> mp;
	int arr[n];
	
	FOR(i, 0, n-1){
		int x; SC(x);
		mp[x] += 1;
		arr[i] = x;
	}
	int res = 0;
	
	FOR(i, 0, n-1){
		std::map<int,int>::iterator cur = mp.find(arr[i]);
		//PR(arr[i]);
		std::map<int,int>::iterator nx = next(cur);
		while(nx != mp.end() && mp[nx->fi] <= 0){
			nx = next(nx);
		}
		if(nx == mp.end()) continue;	
		mp[nx->fi]--;
		res++;
		//PR3(res, nx->fi, mp[nx->fi]);
		//if(mp[nx->fi] == 0) mp.erase(nx->first);	
	}
	cout << res << endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	return 0;
}

