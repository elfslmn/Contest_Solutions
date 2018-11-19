#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i,x,y) for(int i = (x) ; i < (y) ; i++)


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    scanf("%d", &N);

	int res = 0;
	vector<int> st;
    FOR(i,0,N){
		int a;
		scanf("%d", &a);
		
		if(a==1 && i!=0){
		 st.push_back(res);	 
		  res = 0;
		 }
		 res++;
    }
    
   st.push_back(res);
   	cout << st.size() << endl;
    FOR(i,0,st.size() ){
    	cout << st[i] << " " ;
    
    }
    cout << endl;
    
    
    return 0;
}

