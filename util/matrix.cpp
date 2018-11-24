"Matrix Multipication"
// for 2x2, not efficient

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
