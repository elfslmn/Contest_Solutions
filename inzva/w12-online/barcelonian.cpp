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
#define sc2(i,j)	scanf("%lf%lf",&i,&j)
#define sc3(i,j,k)	scanf("%lf%lf%lf",&i,&j,&k)
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

#define EPS 10e-7

int main() {
	double a,b,c;
    sc3(a,b,c);

    double x1,y1, x2,y2;
    sc2(x1,y1);
    sc2(x2,y2);

    if(a == 0 || b == 0){
        double res = abs(x1-x2) + abs(y1-y2);
        printf("%lf\n", res);
        return 0;
    }

    double ly1 = (-c - (a*x1))/b;
    double ly2 = (-c - (a*x2))/b;

    double lx1 = (-c - (b*y1))/a;
    double lx2 = (-c - (b*y2))/a;

    double diag1 = sqrt((ly1-y2)*(ly1-y2) + (x1-lx2)*(x1-lx2));
    double str1 = abs(y1-ly1) + abs(lx2-x2);

    double diag2 = sqrt((y1-ly2)*(y1-ly2) + (lx1-x2)*(lx1-x2));
    double str2 = abs(x1-lx1) + abs(ly2-y2);

    double str3 = abs(x1-x2) + abs(y1-y2);
    double res1 = min3(diag1 + str1 , diag2 + str2 , str3);

    diag1 = sqrt((ly1-ly2)*(ly1-ly2) + (x1-x2)*(x1-x2));
    str1 = abs(ly1-y1) + abs(ly2-y2);

    diag2 = sqrt((lx1-lx2)*(lx1-lx2) + (y1-y2)*(y1-y2));
    str2 = abs(lx1-x1) + abs(lx2-x2);

    double res2 = min(diag1 + str1 , diag2 + str2 );
    printf("%lf\n", min(res1,res2));


	return 0;
}
