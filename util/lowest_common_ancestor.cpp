"Lowest Common Ancestor"
//Jump Pointer Method"
pre-calculate a node’s 2 ith ancestor. 
So we need to keep about log(N) ancestors for each node.

 L[x][y] =  x’s 2^y. ancestors. 
 Hence L[x][0] is basically the parent of x.
 
 
 // init: nlogn
 void init(){
	for(int x=1 ; x<=n ; x++)
		L[x][0] = parent[x];

	for(int y=1 ; y<=logN ; y++)
		for(int x=1 ; x<=n ; x++)
			L[x][y] = L[L[x][y-1]][y-1];

}

//!!! (depthDif >> i)&1 -> depthDif'in ith bitini verir  
#define bit(x,i) (x&(1<<i)) //ith bit of x;

// Query : logn
int LCA(int x,int y){

	if(dep[x] < dep[y])
		swap(x,y);    //Ensuring that x is the deepest node.

	int depthDif = dep[y] - dep[x];
	
	// Equalize their query depth, Uzun olanin, depthDif kadar ustunu alip sorguya devam et. 
	for(int i=0 ; i<=logN ; i++)
		if(bit(depthDif,i)) //This line means we can jump x to its 2^i. ancestor.
			x = L[x][i];
	
	
	// artık bu noktada x ve y nodelari esit depthlerde
	
	if(x == y)
		return x;
	
	// Now we have to jump x and y until they may not jump no more.
	for(int i=logN ; i>=0 ; i--)
	{
		if(L[x][i] != L[y][i]){
			x = L[x][i];
			y = L[y][i];
		}
	}

	return L[x][0];
}









