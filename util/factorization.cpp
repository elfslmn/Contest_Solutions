
"All factors of n - O(sqrt(n))"
set<int> factors;
for(int i = 1;i*i <= n; i++)
	if(n%i == 0)
		factors.insert(i), factors.insert(n/i); // Insert both i and it's pair.
__________________________________________________________________________________		
		
"Prime factorization"
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
____________________________________________________________________________________

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

