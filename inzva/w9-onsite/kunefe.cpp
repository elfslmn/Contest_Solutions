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
#define pb push_back
#define fi first
#define se second
#define mod 1000000007

struct TrieNode{
    TrieNode* child[2];
};

void insert(TrieNode* root, ll key){
    TrieNode* cur = root;
    bitset<64> bits(key);
    for(int i=62; i>=0; i--){
        if(cur->child[bits[i]] == NULL){
            cur->child[bits[i]] = new TrieNode;
        }
        cur = cur->child[bits[i]];
    }
}

ll check(TrieNode* root, ll key){
    TrieNode* cur = root;
    bitset<64> bits(key);
    ll res = 0;
    //cout << "Check ke =" << key << "  bits=" << bits.to_string() << endl;
    for(int i=62; i>=0; i--){
        if(cur->child[!bits[i]] == NULL){
            res += bits[i];
            cur = cur->child[bits[i]];
        }
        else{
            res += (!bits[i]);
            cur = cur->child[!bits[i]];
        }
        //DBG3(i,bits[i], res);
        res *= 2;
    }
    return res/2;
}

int main() {
    int n; sc(n);
    ll x;
    TrieNode* root = new TrieNode;
    insert(root, 0);
    ll pref = 0;
    VLL arr(n+1);
    FOR(i,1,n){
        scl(x);
        arr[i] = x;
        x = x^pref;
        insert(root, x);
        pref = x;
    }

    ll cur = 0;
    ll res = check(root, cur);
    REV(i,n,1){
        cur = cur^arr[i];
        ll op = check(root, cur);
        res = max(res, op^cur);
    }


    PRL(res);

	return 0;
}
