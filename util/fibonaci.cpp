"Fibonacci numbers"
" 1 1 2 3 5 8 ... " f1 = 1 f2 = 1

// nth fibonacci number  O(n)
int f1, f2, f3;
f1 = 1;
f2 = 1;
while(n--){
	f3 = f1 + f2;
    f1 = f2;
    f2 = f3;
}

cout << "nth fibo number:" << f2 << endl ; 
_____________________________________________________________________________

// Fast nth fibonacci number  O(logn)
Calculating Fibonacci with Fast Matrix Exponentiation

	[ fn+1 ]	 [1 1] ^ n     [f1] 
	[ fn   ]  =  [1 0]		x  [f0]
    ______________________________________
					
				  {	[1 1]^(n/2)	  [1 1]^(n/2)
				  {	[1 0]		x [1 0]						if n is even
	[1 1] ^ n     { ________________________________________________________
	[1 0]		= {
				  { [1 1]	[1 1]^(n-1)/2	[1 1]^(n-1)/2	if n is odd
				  { [1 0] x [1 0]		  x [1 0]
				  
				  
int mod = 1e9+7;
typedef vector<vector<ll>> vvll;

vvll matMul(vvll a, vvll b){
	vvll res(2,vector<ll>(2,0));
	FOR(i,0,1){
		FOR(j,0,1){
			FOR(k,0,1){
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= mod;
			}
		}
	}
	return res;
}

vvll fastExp(ll n){
	if(n == 0){
		vvll id(2,vector<ll>(2,0));
		id[0][0] = 1;
		id[1][1] = 1;
		return id;
	}
	vvll temp = fastExp(n/2);

	if(n%2 == 0){
		return matMul(temp,temp);
	}
	else{
		vvll id(2,vector<ll>(2,1));
		id[1][1] = 0;
		return matMul(id, matMul(temp,temp));
	}

}

int main() {
	ll n,a,b;
	scl(n);
	scl(a);
	scl(b);

	vvll mat = fastExp(n);
	ll res = ((b*mat[1][0])%mod + (a*mat[1][1])%mod) % mod;
	PRL(res);

	return 0;
}
