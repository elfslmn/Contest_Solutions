// SUM OF A RANGE ( update single value)
// if you update a range, use lazy version

int ar[NMAX*5]  // original array
int st[NMAX*5]  // segment tree

//ind : current processed index in segment tree
//i : updated index in the original array
//val : update value
// bas, son : segmentin bası ve sonu

int update(int ind, int bas, int son,int i, int val){ 
    // i is not in the segment
	if (i < bas || i > son) return st[ind]; 
	 
	// at leaf
	if( i==bas && i==son){
        st[ind] = val;
        return st[ind];
    } 
	
	// i is in segment, update child segments
	int orta = (bas+son)/2;
	int sol = update(ind*2, bas, orta, i, val);
	int sag = update(ind*2+1, orta+1, son, i, val);
	
    st[ind] = (sol + sag);
	return st[ind];
}

//ind : current processed index in segment tree
// bas, son : segmentin bası ve sonu
// a,b : istenen rangein bası ve sonu

int query(int ind, int bas, int son,int a, int b){
	 // segment is outside of range[a,b] 	( bas son a b  ||  a b bas son )
	if (son < a || b < bas || bas > son)  return 0;  
	
	// segment is inside of given range  ( a bas son b ) 
	if (a <= bas && son <= b) return st[ind];  
	
	// some part of segment is inside given range 
	int orta = (bas+son)/2;
	int sol = query(ind*2, bas, orta, a,b);
	int sag= query(ind*2+1, orta+1, son, a,b);
	
	return (sol+sag);	
}


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


main{

 	// read input and keep in ar[]
 	
 	int np = nextPowerOf2(n)
 	// fill segment tree
	for i = 1 to n{
		update(1,1,np,i,ar[i]);
	}
	
	//to update the index x as val2
	update(1,1,np,x,val2)
	
}

 
