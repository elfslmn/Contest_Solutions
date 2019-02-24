// g++ -std=c++14 -O2 -Wall qa.cpp
// /usr/bin/time -v ./a.out
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
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007

int block = 0;
int a[100005];
int f[100005];

class Query{
    public:
        int l,r,ind;
        Query(int l, int r, int ind){
            this->l = l;
            this->r = r;
            this->ind = ind;
        }

        bool operator<(Query other) const {
            return mp(l/block , r) < mp(other.l/block , other.r);
        }
};

void add(int i, int & num){
    if(f[a[i]] == 0) num++;
    f[a[i]]++;
}

void del(int i, int & num){
    if(f[a[i]] == 1) num--;
    f[a[i]]--;
}


int main() {
	int n,q; sc2(n,q);

    block = sqrt(n);

    FOR(i,1,n){
        sc(a[i]);
    }

    vector<Query> qs;
    int l,r;
    FOR(i,0,q-1){
        sc2(l,r);
        Query q = Query(l,r,i);
        qs.pb(q);
    }
    sort(ALL(qs));

    VI ans(q);

    l = 0;
    r = -1;
    int num = 0;
    for(auto q : qs){
        while(l < q.l){
            del(l, num);
            l++;
        }
        while(l > q.l){
            l--;
            add(l, num);
        }
        while(q.r < r){
            del(r, num);
            r--;
        }
        while(q.r > r){
            r++;
            add(r, num);
        }
        DBG2(l,r);
        PRV(f);
        cout << "Num="<<num << endl;
        ans[q.ind] = num;
    }

    FOR(i,0,q-1){
        PR(ans[i]);
    }

	return 0;
}
