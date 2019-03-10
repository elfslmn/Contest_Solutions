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

int link[5000006];
int size[5000006];

//find returns the representative for an element x
int find(int x) {
	VI temp;
	while (x != link[x]){
		temp.pb(x);
		x = link[x];
	}
	for(int i : temp){
		link[i] = x;
	}
	return x;
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (size[a] < size[b]) swap(a,b);
	size[a] += size[b];
	link[b] = a;
}

//checks whether elements a and b belong to the same set
bool same(int a, int b) {
	return find(a) == find(b);
}
int n,m;

int ind(int r, int c){
	return r*(n+1) + c + 1;
}

int main() {
    int A,B; sc2(A,B);
    sc2(n,m);
    VI b(m+1,0);
    VI a(n+1,0);
    FOR(i,1,n){
        sc(a[i]);
    }
	sort(a.begin(), a.end());
	FOR(i,1,n){
		a[i-1] = a[i]-a[i-1];
    }
	a[n] = A - a[n];
    sort(a.begin(), a.end());
	//FOR(i,0,n) printf("%d ", a[i]); printf("\n");

    FOR(i,1,m){
        sc(b[i]);
    }
	sort(b.begin(), b.end());
	FOR(i,1,m){
		b[i-1] = b[i]-b[i-1];
    }
	b[m] = B - b[m];
    sort(b.begin(), b.end());
	//FOR(i,0,m) printf("%d ", b[i]); printf("\n");

    FOR(i,1,(n+1)*(m+1)){
        link[i] = i;
        size[i] = 1;
    }

	int ai = 0, bi=0 ;
	int u,v,w, gi;
	ll res = 0;
	while(true){
		if(ai <= n && bi <= m){
			if(a[ai] < b[bi]){ // remove as, unite vertical
				w = a[ai];
				FOR(r,0,m-1){
					u = ind(r,ai);
					v = ind(r+1,ai);
					if (!same(u,v)){
			            unite(u,v);
			            res += w;
			        }
				}
				ai++;
			}
			else{  // remove bs, unite horizontal
				w = b[bi];
				FOR(c,0,n-1){
					u = ind(bi,c);
					v = ind(bi,c+1);
					if (!same(u,v)){
			            unite(u,v);
			            res += w;
			        }
				}
				bi++;
			}
		}
		else if(ai <= n){
			w = a[ai];
			FOR(r,0,m-1){
				u = ind(r,ai);
				v = ind(r+1,ai);
				if (!same(u,v)){
					unite(u,v);
					res += w;
				}
			}
			ai++;
		}
		else if(bi <= m){
			w = b[bi];
			FOR(c,0,n-1){
				u = ind(bi,c);
				v = ind(bi,c+1);
				if (!same(u,v)){
					unite(u,v);
					res += w;
				}
			}
			bi++;
		}
		else{
			break;
		}

	}

    PRL(res);

	return 0;
}
