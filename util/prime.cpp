
//is Prime  O(sqrt n)
bool isprime(int n) {
	if (n < 2) return false;
	for (int x = 2; x*x <= n; x++) {
		if (n%x == 0) return false;
	}
	return true;
}
__________________________________________________________________

// Sieve - is Prime for multiple queries O (nloglogn)
int sieve[n+1]
for (int x = 2; x <= n; x++) {
	if (sieve[x]) continue;
	for (int u = 2*x; u <= n; u += x) {
		sieve[u] = x;
	}
}

if(sieve[k] == 0) k is prime
_______________________________________________________________

// Prime factorization
vector<int> factors(int n) {
	vector<int> f;
	for (int x = 2; x*x <= n; x++) {
		while (n%x == 0) {
			f.push_back(x);
			n /= x;
		}
	}
	if (n > 1) f.push_back(n);
	return f;
}
______________________________________________________________________________

"Prime factorization of all numbers between 1 and n"
// use a technique similar to sieve

vector<vector<int>> pfactors;
vector<bool> isPrime;

int sieve(int n ){
	isPrime[0] = false;
	isPrime[1] = false;
	for(int i=2; i*i<n; i++){
		if(isPrime[i]){
			pfactors[i].push_back(i); // i kendisinin asal bolenidir
			for(int j=i*2; j<n; j+=i){
				isPrime[j] = false;
				pfactors[j].push_back(i); // i, j nin bir asal bolenidir
			}
		}
	}

}

int main(){
	//initialize isPrime all true
	
	//take memory for factors
	pfactors.resize(n);
}


