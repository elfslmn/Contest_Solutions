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
#define ceil(a,k) ((a-1)/k + 1) // round up a/k
#define min3(x,y,z) min(x,min(y,z))
#define max3(x,y,z) max(x,max(y,z))

#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define mod 1000000007

struct TrieNode{
    TrieNode* child[26];
    bool end = false;
    int alt = 0;
};

void addKey(TrieNode* root, string key){

    root-> alt += 1;
    TrieNode* cur = root;
    FOR(i,0,key.size()-1){
        if(cur->child[key[i]-'a'] == nullptr){
            cur->child[key[i]-'a'] = new TrieNode;
        }
        cur = cur->child[key[i]-'a'];
        cur-> alt += 1;
    }
    cur->end = true;
}

int solve(TrieNode* root, string partial){
    TrieNode* cur = root;
    FOR(i,0,partial.size()-1){
        if(cur->child[partial[i]-'a'] == nullptr){
            return 0;
        }
        cur = cur->child[partial[i]-'a'];
    }
    return cur->alt;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    string com, key;
    cin >> n;
    TrieNode* root = new TrieNode;
    FOR(i,1,n){
        cin >> com >> key;
        if(com == "add"){
            addKey(root, key);
        }
        else if(com == "find"){
            cout << solve(root, key) << endl;
        }
        else{
            assert(false);
        }
    }


	return 0;
}
