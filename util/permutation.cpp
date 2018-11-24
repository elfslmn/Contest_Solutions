"PERMUTATION"  - order is important

// to find only distirubution count -> P(n,k) = n! / (n-k)!
long long mult = 1, destination = n - k;
while(n > destination){
	mult *= n;
	n--;
}
_______________________________________________________________

// std builtin permutation function
 " next_permutation(myarr,myarr+n) "
 Rearranges the elements in the range [first,last) into the next lexicographically greater permutation.
int main () {
  int myints[] = {1,2,3};

  sort (myints,myints+3);

  do 
  {
   cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
  } 
  while ( next_permutation(myints,myints+3) );

 std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

  return 0;
}

Output : The 3! possible permutations with 3 elements:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
After loop: 1 2 3
____________________________________________________________________________________________________________

//e.g. I want to distrubute 5 elements to 3 set, enumerate all possible distributions of 5 elements into 3 different sets. such as {1,1,2,1,3}  ( can be done with built-in function ) 

int ar[100];

void enumerate( int element, int n ){

	if( element > n ){ // Base case
		for( int i=1 ; i<=n ; i++ ){
			printf("%d ", ar[i]);
		}
		printf("\n");
		return;
	}
	for( int i=1 ; i<=3 ; i++ ){
		ar[element] = i;
		enumerate(element + 1, n);
	}
}

int main(){
	enumerate(1, 5);
	return 0;
}
__________________________________________________________________________________________________________















