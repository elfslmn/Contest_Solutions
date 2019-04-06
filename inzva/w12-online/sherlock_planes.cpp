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
    double x,y,z;
};

struct Vec{
    double x,y,z;
};

Vec cross(Vec a, Vec b){
    Vec v = {a.y*b.z - a.z*b.y , a.z*b.x - a.x*b.z , a.x*b.y - a.y*b.x };
    return v;
}
#define dot(u,v)   ((u).x * (v).x + (u).y * (v).y + (u).z * (v).z)

int main() {
    int t; sc(t);
    while(t--){
        int x,y,z;
        sc3(x,y,z);
        Point p0 = {x,y,z};
        sc3(x,y,z);
        Point p1 = {x,y,z};
        sc3(x,y,z);
        Point p2 = {x,y,z};

        Vec u = {p1.x-p0.x, p1.y-p0.y, p1.z-p0.z};
        Vec v = {p2.x-p0.x, p2.y-p0.y, p2.z-p0.z};
        Vec n = cross(u,v);

        double d = dot(n,p0);
        // plane ax + by + cz = d , n = {a,b,c}
        sc3(x,y,z);
        if(n.x * x + n.y * y + n.z * z == d){
            printf("YES\n");
        }
        else printf("NO\n");
    }
	return 0;
}
