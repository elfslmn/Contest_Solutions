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

int a[100005];

int main() {
	ios::sync_with_stdio(false);
    int n1,n2,n3;
    stack<int> s1,s2,s3;
    s1.push(0);
    s2.push(0);
    s3.push(0);

    cin >> n1 >> n2 >> n3;
    FOR(i,1,n1){
        cin >> a[i];
    }
    REV(i,n1,1){
        s1.push(s1.top() + a[i]);
    }
    FOR(i,1,n2){
        cin >> a[i];
    }
    REV(i,n2,1){
        s2.push(s2.top() + a[i]);
    }
    FOR(i,1,n3){
        cin >> a[i];
    }
    REV(i,n3,1){
        s3.push(s3.top() + a[i]);
    }

    int cur = s1.top();
    int min = 1;
    int ct = 1;

    while(ct < 3){
        //cout << cur <<"," << ct <<","<<min << endl;
        if(min == 1){
            while(!s2.empty() && s2.top() > cur) s2.pop();
            if(s2.empty()){
                cur = 0;
                break;
            }
            else if(s2.top() == cur){
                ct++;
                min = 2;
            }
            else{
                cur = s2.top();
                ct = 1;
                min = 2;
            }
        }
        else if(min == 2){
            while(!s3.empty() && s3.top() > cur) s3.pop();
            if(s3.empty()){
                cur = 0;
                break;
            }
            else if(s3.top() == cur){
                ct++;
                min = 3;
            }
            else{
                cur = s3.top();
                ct = 1;
                min = 3;
            }

        }
        else if(min == 3){
            while(!s1.empty() && s1.top() > cur) s1.pop();
            if(s1.empty()){
                cur = 0;
                break;
            }
            else if(s1.top() == cur){
                ct++;
                min = 1;
            }
            else{
                cur = s1.top();
                ct = 1;
                min = 1;
            }

        }
        else {
            assert(false);
        }
    }

    cout << cur << endl;


	return 0;
}
