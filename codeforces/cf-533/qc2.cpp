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

#define mod 1000000007
int main() {
    int n,l,r; sc3(n,l,r);
    int c3 = (r-l+1) / 3;
    int c2 = c3;
    int c1 = c3;
    if(l % 3 == 0){
        if(r %3 == 0) c3++;
        else if(r % 3 == 1){
            c1++;
            c3++;
        }
    }
    else if(l % 3 == 1){
        if(r %3 == 1) c1++;
        else if(r % 3 == 2){
            c1++;
            c2++;
        }
    }
    else{
        if(r %3 == 2) c2++;
        else if(r % 3 == 0){
            c2++;
            c3++;
        }
    }

    vector<ll> f1(n+1, 0);
    vector<ll> f2(n+1, 0);
    vector<ll> f3(n+1, 0);
    f1[0] = 1;
    f2[0] = 1;
    f3[0] = 1;

    f1[1] = c1;
    f2[1] = c2;
    f3[1] = c3;

    FOR(i,2,n){
        f1[i] = ((c1*f3[i-1])%mod + (c2*f2[i-1])%mod + (c3*f1[i-1])%mod ) %mod;
        f2[i] = ((c2*f3[i-1])%mod + (c3*f2[i-1])%mod + (c1*f1[i-1])%mod ) %mod;
        f3[i] = ((c3*f3[i-1])%mod + (c1*f2[i-1])%mod + (c2*f1[i-1])%mod ) %mod;
    }


    PRL(f3[n]);


	return 0;
}
