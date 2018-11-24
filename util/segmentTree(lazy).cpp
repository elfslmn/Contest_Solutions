
int a[5*NMAX];			//original array
int st[5*NMAX] ={0};	//segment tree
int l[5*NMAX] ={0};		//lazy updates

// increase every element in range [a,b] by ch
void update(int ind, int bas, int son,int a, int b, int ch){
    
    //process waiting updates
    if(l[ind] != 0){
        st[ind] += l[ind]*(son-bas+1);
        
        if(son !=bas){ // not leaf
            l[2*ind] += l[ind];
            l[2*ind+1] += l[ind];        
        }      
        l[ind] = 0;
    }
    //out of range
    if(a >son || b<bas || bas > son ){
        return;
    }
    
    // fully in range
    if( bas >= a && b >= son){
        st[ind] += (son-bas+1)*ch;
        if( son != bas){
            l[2*ind] += ch;
            l[2*ind+1] += ch;  
        }
        return;
    }
    
    // some part in range
    int orta = (bas+son) /2;  
    update(2*ind, bas, orta, a,b,ch);
    update(2*ind+1, orta+1, son, a,b,ch);
    
    st[ind] = st[2*ind] + st[2*ind+1];
    return;
}

int query(int ind, int bas, int son,int a, int b){
    //process waiting updates
    if(l[ind] != 0){
        st[ind] += l[ind]*(son-bas+1);
        
        if(son != bas){ // not leaf
            l[2*ind] += l[ind];
            l[2*ind+1] += l[ind];        
        }      
        l[ind] = 0;
    }
    
   //out of range
    if(a >son || b<bas || bas > son){
        return 0;
    }
    
    // segment fully in range [a,b]
    if( bas >= a && b >= son){
        return st[ind];
    }
    
    // some part in range
    int orta = (bas+son) /2; 
    int sol = query(2*ind, bas, orta, a,b);
    int sag = query(2*ind+1, orta+1, son, a,b);
    return sol+sag;
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

int main() {

     // read input and keep in ar[]
 	
 	int np = nextPowerOf2(n)
 	// fill segment tree
    for i = 1 to n{
        update(1,1,np,i,i,ar[i]);
    }
    
     
    return 0;
}

