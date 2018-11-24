	// Subset of an n-element set

	arr[n];

	for (int b = 0; b < (1<<n); b++) {
		vector<int> subsetIndices;
		for (int i = 0; i < n; i++) {
			if (b&(1<<i)) subsetIndices.push_back(i);
		}
		//process subset
		// if subsetIndices has 2 and 5, subset is = {arr[2], arr[5] }
	}
	_______________________________________________________________________

	// n den buyuk en kucuk 2nin kuvveti
	int nextPowerOf2(int n){
		int count = 0;
		if (n && !(n & (n - 1)))
		    return n;
		while( n != 0){
		    n >>= 1;
		    count += 1;
		}
		return 1 << count;
	}
	_______________________________________________________________________

	// n den kucuk, en buyuk 2nin kuvveti
	int highestPowerof2(int n)
	{
	   int p = (int)log2(n);
	   return (int)pow(2, p); 
	}
	_______________________________________________________________________

	bool isPowerOfTwo(int x)
	{
	    return x && (!(x&(x-1)));
	}
	_______________________________________________________________________

	// number of 1 bits in integer n	
	__builtin_popcountll(ll n)
    __builtin_popcount(int n)
	_______________________________________________________________________    

	//Number of digits in N 
	int len = floor(log10(N)) + 1;    
	_______________________________________________________________________    
	  
	// Most significant digit of N
	double K = log10(N);
	K = K - floor(K);
	int msb = pow(10, K);  
	_______________________________________________________________________ 
	  
	// GCD       
	cout << __gcd(5,5) << endl;  //5
	cout << __gcd(5,0) << endl;  //5
	cout << __gcd(0,5) << endl;	 //5
	cout << __gcd(0,0) << endl;  //0      
		    
		    
		    
		    
		    
	_______________________________________________________________________
