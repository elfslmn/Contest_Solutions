"EXPONENT" - find value of n^k

// Fast Exponentiation - O(logk)
		
		  { n^(k/2) * n^(k/2) 				if n is even	
	n^k	= {
		  { n * n^[(k-1)/2] * n^[(k-1)/2] 	if n is odd


#define mod 1000000007
long long fastExp(long long n, long long k){
	if(k == 0) return 1;
	if(k == 1) return n;
	
	long long temp = fastExp(n, k/2);

	// If k is odd return n * temp * temp
	// If k is even return temp * temp
	// Take mod, since we can have a large number that overflows from long long
	if((k&1) == 1) // odd
		return (n * temp * temp) % mod;
	else // even
		return (temp * temp) % mod;
}


