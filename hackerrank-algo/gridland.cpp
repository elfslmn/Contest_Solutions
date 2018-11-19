#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int>     VI;
typedef pair<int, int>  PII;
typedef pair <ll, ll>  PLL;
typedef vector<pair<int, int>>  VPII;

using namespace std;

#define FOR(i,x,y) for(ll i=(ll)(x); i<(ll)(y); i++)

#define MEM(a)		memset(a,0,sizeof(a))
#define MINUS(a)	memset(a,0xff,sizeof(a))

#define DBG2(i,j)	cout << i << "," << j << endl
#define DBG3(i,j,k)	cout << i << "," << j << "," << k << endl

#define pb(a) push_back(a)
#define fi first
#define se second

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    map<int, VPII > mp;
    FOR(i,0,k){
        int r, c1,c2;
        scanf("%d%d%d", &r, &c1, &c2);
        //DBG3(r,c1,c2);
        bool comb = false;
        FOR(j, 0, mp[r].size()){
            //out completely
            if( c2 < mp[r][j].fi  || mp[r][j].se < c1 ) continue;
            else{
                mp[r][j].fi = min(mp[r][j].fi , c1);
                mp[r][j].se = max(mp[r][j].se , c2);
                comb = true;
                c1 = mp[r][j].fi;
                c2 = mp[r][j].se;
            }    
        }
        if(!comb) {
            mp[r].push_back({c1,c2}); 
            
        }
    }
    
    long long int res = (ll)n*(ll)m;
    for(auto x : mp){
        VPII r = x.se;
        for(auto p : r){
            res -= ((ll)p.se - (ll)p.fi +(ll)1);
            //DBG3(res,p.fi,p.se);
        }
    }
    cout << res << endl;

    return 0;
}

