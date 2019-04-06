// g++ -std=c++14 -O2 -Wall qa.cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef vector<int>		VI;
typedef vector<bool>  	VB;
typedef vector<ll>  	VLL;
typedef pair<int, int>  PII;
typedef pair <ll, ll>  	PLL;
typedef vector<PII>  	VPII;
typedef tuple<int,int,int>  TI;

typedef unordered_set<int> USI;
typedef set<int> SI;

typedef unordered_map<int, int> UMP;
typedef map<int, int> MP;

typedef queue<int> QI;
typedef queue<PII> QP;

typedef priority_queue<int> PQI;
typedef priority_queue<PII> PQP;

#define sc(n)		scanf("%d",&n)
#define sc2(i,j)	scanf("%d%d",&i,&j)
#define sc3(i,j,k)	scanf("%d%d%d",&i,&j,&k)
#define scl(n) 		scanf("%lld",&n)
#define scf(n) 		scanf("%lf",&n)
#define scs(n)  	scanf("%s",n)

#define FOR(i,x,y) 	for(int i=(x); i<=(y); i++)
#define REV(i,x,y) 	for(int i=(x); i>=(y); i--)
#define ALL(v) 		(v).begin(),(v).end()
#define SZ(v) 		(int)v.size()

#define PR(i)		printf("%d\n", (i))
#define PRL(i)		printf("%lld\n", (i))
#define PRA(arr)	FOR(i,0,(arr.size()-1)){ cout << arr[i] << " ";} cout << "\n"
#define PRV(v)		for(auto i : v) { cout << i << " ";} cout << "\n"

#define DBG2(i,j)	cout <<"DBG: "<< i << " " << j << endl
#define DBG3(i,j,k)	cout <<"DBG: "<< i << " " << j << " " << k << endl

#define bit(x,i) (x&(1<<i)) //ith bit of x;
#define ceilint(a,k) ((a-1)/k + 1) // round up a/k
#define min3(x,y,z) min(x,min(y,z))
#define max3(x,y,z) max(x,max(y,z))

#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define mod 1000000007

struct Point{
    int x,y;
};

inline int dist2(Point a, Point b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}


int main() {
    int a,b; sc2(a,b);
    if(a > b) swap(a,b);
    int a2 = a*a;
    VPII res;
    bool found = false;
    FOR(y,a*-1,a){
        FOR(x,a*-1, a){
            if(x == 0 || y == 0) continue;
            if(x*x + y*y == a2){
                if(a == b && abs(x) == abs(y)) continue;
                if(b*y % a == 0 && b*x % a == 0){
                    res.pb({x,y});
                    res.pb({b*y/a, -b*x/a});
                    found = true;
                    break;
                }
            }
        }
        if(found) break;
    }
    if(found){
        printf("YES\n");
        printf("0 0\n");
        printf("%d %d\n", res[0].fi, res[0].se);
        printf("%d %d\n", res[1].fi, res[1].se);
    }
    else printf("NO\n");

	return 0;
}
