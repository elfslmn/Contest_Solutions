#include <bits/stdc++.h>

using namespace std;

struct frac{
	int alt,ust;
};

int main(){
	frac a = frac{2,4};
	cout << a.alt << "," << a.ust << endl;	// 2,4
	//frac* b; // b-> gives segment fault during b = frac ..  since b pointing to a random memory
	frac* b = (frac*)malloc( sizeof(frac) );
	
	b->alt = 5;
	b->ust = 5;
	cout << b->alt << "," << b->ust << endl;	//5,5
	
	b = &a;
	cout << b->alt << "," << b->ust << endl;	//2,4
	
	//free(b); 	// since b is now point to a, do not be freed manually, 
				// gives double free or corruption error, it will freed end of its scope
				// should be freed if not write b=&a;
				
	int s;
	int &r = s;

	cout << (&r == &s) << endl;
	
	return 0;
}

//int  a = b  is setting a's VALUE to b's VALUE
//int* a = &b is setting a's VALUE to the ADDRESS of b
//int& a = b  is setting a's ADDRESS to b's ADDRESS (a is a reference to b) 
