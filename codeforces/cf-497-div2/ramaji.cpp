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
	unordered_set<char> vovel = {'a','e','i','o','u'};
	
	string s;
    cin >> s;
    int n = s.size();
    bool isB = true;
    bool needv = false;
    FOR(i, 0, n-1){
       if(vovel.count(s[i]) == 0){
           if(needv){
               isB = false;
               break;
           }
           if(s[i] == 'n') continue;
            needv = true;
       } 
       else{
           needv = false;
       }
    }

    if(isB) cout << "YES" <<endl;
    else cout << "NO" << endl;

	return 0;
}

