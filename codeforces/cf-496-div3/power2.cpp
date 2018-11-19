
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
#define FOR(i,x,y) for(int i = (x) ; i < (y) ; i++)


typedef long long ll;
typedef vector<int>     VI;
typedef pair<int, int>  PII;
typedef vector<PII>     VPII;



int main() {
    int N;
    scanf("%d", &N);

	int ar[N];
    FOR(i,0,N){
		int a;
		scanf("%d", &a);
		ar[i] = a;
	}
	
	sort(ar, ar+N);
	
	int good[N] ={0};
	int res = 0;
	FOR(i,0,N){
		if(i != 0 && ar[i] == ar[i-1]){
			good[i] = good[i-1];
			continue;
		} 
		FOR(j,i+1,N){
			int s = ar[i] + ar[j];
			if((s & (s-1)) == 0 ){
				good[i] = 1;
				good[j] = 1;
			}			
		}
	}
	FOR(i,0,N){
		if(good[i] == 0) res++;
	}
	
	cout << res << endl;

return 0;
}

