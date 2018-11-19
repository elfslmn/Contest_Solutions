// g++ -std=c++11 -O2 -Wall
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>  VI;
typedef pair<int, int>  PII;
typedef pair <ll, ll>  PLL;
typedef vector<pair<int, int>>  VPII;

#define SC(i) scanf("%d", &(i))
#define SC2(i,j) scanf("%d%d", &(i), &(j))
#define SC3(i,j,k) scanf("%d%d%d", &(i), &(j), &(k))

#define FOR(i,x,y) for(ll i=(ll)(x); i<= (ll)(y); i++)
#define REV(i,x,y) for(ll i=(ll)(x); i>= (ll)(y); i--)

#define MEM(a)		memset(a,0,sizeof(a))
#define MINUS(a)	memset(a,0xff,sizeof(a))

#define PR(i)		printf("%d\n", (i))
#define PR2(i,j)	cout << i << " " << j << endl
#define PR3(i,j,k)	cout << i << " " << j << " " << k << endl

#define pb(a) push_back((a))
#define fi first
#define se second


int main() {
		
	string s;
	getline(cin ,s );
	int n= s.size();
	bool saw2  = false;
	int c[3] ={0,0,0};
	int i= 0;
	
	while(i<n){
		if(s[i] == '2'){
			saw2= true;
			i++;
			c[2]++;
		}
		else if(s[i] == '0'){
			if(saw2 == true){
				FOR(j,0,c[0]-1) printf("0");
				FOR(j,0,c[1]-1) printf("1");
				FOR(j,0,c[2]-1) printf("2");
				saw2 = false;
				MEM(c);
			}
			i++;
			c[0]++;						
		}
		else{
			i++;
			c[1]++;	
		}	
	}
	FOR(j,0,c[0]-1) printf("0");
	FOR(j,0,c[1]-1) printf("1");
	FOR(j,0,c[2]-1) printf("2");
	
	printf("\n");

	return 0;
}


