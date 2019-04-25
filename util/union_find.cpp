"Union Find"
//any sequence of M union and find operations on N objects 
- Without size and path compr.  -> MN
- Only size						-> N + MlogN
- Only path compr.				-> N + MlogN 
- Both size and path compr.		-> N + Mlg*N  ( lg* : loop count of take log of a number until reaching 1 ) 
_______________________________________________________________________

"Implementation"
int link[nmax];
int size[nmax];

for (int i = 1; i <= n; i++) link[i] = i;
for (int i = 1; i <= n; i++) size[i] = 1;
_____________________________________________________________________				
				
//find returns the representative for an element x
int find(int x) {					  
	while (x != link[x]){
	    link[x] = link[link[x]]; // path compression to speed up
		x = link[x]; 
	}
	return x;						  
}
_______________________________________________________________________

void unite(int a, int b) {				
	a = find(a);					
	b = find(b);						
	if (size[a] < size[b]) swap(a,b);	 // add small group to big one
	size[a] += size[b];					
	link[b] = a;						
}
_________________________________________________________________________

//checks whether elements a and b belong to the same set
bool same(int a, int b) {		
	return find(a) == find(b);	
}
________________________________________________________________________

//Kruskal's Minimum spanning tree
//edgeleri uzunluğuna göre küçükten buyuge sırala
// construct graph
for (edge btw a and b) {
	if (!same(a,b)) unite(a,b);
}
