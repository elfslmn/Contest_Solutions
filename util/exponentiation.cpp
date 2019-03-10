"EXPONENT" - find value of n^k

// Fast Exponentiation - O(logk)
		
		  { n^(k/2) * n^(k/2) 				if n is even	
	n^k	= {
		  { n * n^[(k-1)/2] * n^[(k-1)/2] 	if n is odd


#define mod 1000000007
ll fastExp(ll n, ll k){
	if(k == 0) return 1;
	if(k == 1) return n;
	
	ll temp = fastExp(n, k/2);

	// If k is odd return n * temp * temp
	// If k is even return temp * temp
	if((k&1) == 1) // odd
		return (((n * temp)%mod) * temp) % mod;
	else // even
		return (temp * temp) % mod;
}


