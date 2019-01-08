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
___________________________________________________________________________

//SEGMENT TREE 2ND IMPLEMENTAION

// tree[ind] dizinin [l,r] araliginin cevabini saklar.
void build(int ind,int l,int r) {
	if (l == r) { // leaf
		tree[ind] = a[l]; //bu dugum dizinin l. elamaninin cevabini saklar
	}
	else {
		int mid = (l + r) / 2;
		build(ind * 2,l,mid);
		build(ind * 2 + 1,mid + 1,r);
		// [l,r] araliginin cevabini[l,mid] ve [mid + 1,r] araliklarinin cevaplarinin birlesmesiyle olusur.
		tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
	}
	return;
}

//ind : current processed index in segment tree
// [lq,rq] sorguda cevabini aradigimiz aralik.
// [l,r] ise agactaki ind nolu node'da cevabini sakladigimiz aralik.
int query(int ind,int l,int r,int lq,int rq) {
	if (l > rq or r < lq) //bulundugumuz aralik cevabini aradigimiz araligin disinda.
		return 0;
	if (l >= lq and r <= rq) //cevabini aradigimiz aralik bu araligi tamamen kapsiyor.
		return tree[ind];
	int mid = (l + r) / 2;
	return query(ind * 2,l,mid,lq,rq) + query(ind * 2 + 1,mid + 1,r,lq,rq);
}

void update(int ind,int l,int r,int x,int val) {
	if (l > x || r < x) //bulundugumuz aralik x indeksli elemani icermiyor.
		return;
	if (l == x and r == x) {
		tree[ind] = val; //x indeksli elemani iceren yaprak dugumunun cevabini guncelliyoruz.
		return;
	}
	int mid = (l + r) / 2;
	update(ind * 2,l,mid,x,val); // update left tree
	update(ind * 2 + 1,mid + 1,r,x,val); // update right tree
	tree[ind] = tree[ind * 2] + tree[ind * 2 + 1]; // update tree
}


























 
