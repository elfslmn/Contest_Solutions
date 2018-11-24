int link[nmax];
int size[nmax];

for (int i = 1; i <= n; i++) link[i] = i;
for (int i = 1; i <= n; i++) size[i] = 1;				
				
//find returns the representative for an element x
int find(int x) {					  
	while (x != link[x]) x = link[x]; 
	return x;						  
}

void unite(int a, int b) {				
	a = find(a);					
	b = find(b);						
	if (size[a] < size[b]) swap(a,b);	
	size[a] += size[b];					
	link[b] = a;						
}

//checks whether elements a and b belong to the same set
bool same(int a, int b) {		
	return find(a) == find(b);	
}


//msp
//edgeleri uzunluğuna göre küçükten buyuge sırala
// construct graph
for (edge btw a and b) {
	if (!same(a,b)) unite(a,b);
}
