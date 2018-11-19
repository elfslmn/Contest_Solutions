#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
#define FOR(i,x,y) for(int i = (x) ; i < (y) ; i++)


int main() {
	string a,b; 

	getline(cin, a);
	getline(cin, b);
	
	//cout << a << "," << b<< endl;
	
	
	char aa[200005]; 
	char bb[200005];
	
	int sa = a.length();
	int sb = b.length();
	if(sa == 0){
		cout << sb << endl;
		return 0;
	}
	if(sb == 0){
		cout << sa << endl;
		return 0;
	}
     
    // copying the contents of the 
    // string to char array
    strcpy(aa, a.c_str());
     strcpy(bb, b.c_str());
     
     while(sa>=0 && sb>=0){
     	if(aa[sa-1] != bb[sb-1]) break;
     	else{
     		sa--;
     		sb--;
     	}
     }
     if(sa+sb <0) {
     	cout << 0 <<endl;
     	return 0;
     }
     cout << sa+sb << endl;
     
     
     
     
	


	return 0;
}
