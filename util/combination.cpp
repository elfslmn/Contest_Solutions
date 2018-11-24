"COMBINATION"  - order is not important

C(n,k) = n! / [(n-k)! * k! ]

vector< vector<long long> > savedVal;

long long combination(int n, int k){
	// Base condition
	if(k == n || k == 0) {
		savedVal[n][k] = 1LL;
		return savedVal[n][k];
	}

	// Base condition
	if(k == n-1 || k == 1){
		savedVal[n][k] = (long long)n;
		return savedVal[n][k];
	}

	if(savedVal[n][k] != 0) 
		return savedVal[n][k];

	// Save the output of the recursion
	savedVal[n][k] = (combination(n-1, k) + combination(n-1, k-1));
	return savedVal[n][k];
}

int main() {
	int n,k;
	// Read the input and resize the array
	scanf("%d %d", &n, &k);
	savedVal.resize(n+1, vector<long long>(k+1, 0LL));

	long long combinationVal = combination(n, k);

	printf("The output is %lld\n", combinationVal);

	return 0;
}









