#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,x,y) for(int i = (x) ; i < (y) ; i++)


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    getline(cin, s); 
    
    char ar[200005];
     strcpy(ar, s.c_str());
     
     long long int l = s.length();
     
     
     long long int res = 0;
     long long int sum = 0;
     
     int div[l+1] ={0};
     int start = 0;
     for(long long int i = 0 ; i < l ; i++){
     	long long int c = ar[i] -'0';
     	if( c == 0){
			sum = 0;
			div[i] = 0;
			div[i+1] = 1;
			start = i+1;
			res++;
     	}
     	else{
     		sum+= c;
     		if(sum%3 == 0) {
				sum = 0;
				div[i+1] = 1;
				for(int k=start; k <=i+1; k++){
					div[k] = 1;
				}
				start = i+1;
				res++;
     		}
     	}  	    	
     }
     
     
     sum = 0;
     for(long long int i = l-1 ; i >=0 ; i--){
     	long long int c = ar[i] -'0';
     	if( c == 0){
			sum = 0;
     	}
     	else{
     		sum+= c;
     		if(sum%3 == 0) {
				sum = 0;
				if(div[i] ==0) res++;
     		}
     	}  	    	
     }

     
         
     
    
    cout << res << endl;
    return 0;
}
