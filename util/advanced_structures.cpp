"ADVANCED DATA STRUCTURES"

//Topics
1) Segment Tree
2) Segment Tree with Lazy Updates
3) Prefix sum
4) Sparse Table
5) Fenwick Tree ( Binary-indexed tree, BIT)
6) Binary Search Tree ( BST)
7) Treap
__________________________________________________________

"SEGMENT TREE"

#define nmax ??
int tree[4*nmax];

void update(int i, int l, int r, int x, int val){
    if(r == x &&  l == x){ // leaf
        tree[i] = val;
        return;
    }

    if(x < l || r < x){ // out of range
        return;
    }

    int mid = (r+l)/2;
    update(2*i, l, mid, x, val);
    update(2*i+1, mid+1, r, x, val);
    tree[i] = tree[2*i] + tree[2*i+1];
}

int query(int i, int l, int r, int ql, int qr){
    if(r < ql || qr < l){ // segment lr not in range qlr
        return 0;
    }
	
	// segment lr fully inside in range qlr
    if(ql <=l && r <= qr) return tree[i];

    int mid = (r+l)/2;
    int lval = query(2*i, l, mid, ql, qr);
    int rval = query(2*i+1, mid+1, r, ql, qr);
    return (lval + rval) ;
}

update(1,1,n,3,10) // update index 3 as 10
query(1,1,n,4,6) // sum of the elements between 4 and 6 (both inclusive)
___________________________________________________________________________

"SEGMENT TREE LAZY UPDATE"
// Needed in case of range updates

#define nmax ??

ll tree[4*nmax];
ll lazy[4*nmax];

void update(int i, int l, int r, int ql, int qr, ll val){ // val = change
    // !! out of range cond. CANNOT be here
    // apply lazy
    if(lazy[i]){
        tree[i] += (lazy[i]*(r-l+1));
        if(r != l){ // not leaf
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }

    if(r < ql || qr < l){ // lr out of range qlr
        return; // lazy should be applied even if out of range
    }

    if(ql <= l && r <= qr){ // lr fully inside qlr
        tree[i] += ((r-l+1)*val);
        if(r != l){ // not leaf
            lazy[2*i] += val;
            lazy[2*i+1] += val;
        }
        return;
    }

    int mid = (l+r)/2;
    update(2*i, l, mid, ql, qr, val);
    update(2*i+1, mid+1, r, ql, qr, val);
    tree[i] = tree[2*i] + tree[2*i+1];
}

ll query(int i, int l, int r, int ql, int qr){
    // apply lazy
    if(lazy[i]){
        tree[i] += (lazy[i]*(r-l+1));
        if(r != l){ // not leaf
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }

    if(r < ql || qr < l){ // lr out of range qlr
        return 0LL;
    }

    if(ql <= l && r <= qr){ // lr fully inside qlr
        return tree[i];
    }

    int mid = (l+r)/2;
    ll lval = query(2*i, l, mid, ql, qr);
    ll rval = query(2*i+1, mid+1, r, ql, qr);
    return lval + rval;
}

update(1,1,n,4,6,3) // increase all elemnts btw index [4,6] by 3
query(1,1,n,4,6) // sum of the elements between [4,6] (both inclusive)
__________________________________________________________________________

"PREFIX SUM"
build -> O(N)
query -> O(1)

int n,sum[N],a[N];
void build() {
	for (int i = 1 ; i <= n ; i++)
	sum[i] = sum[i - 1] + a[i];
}
int query(int l,int r) {
	return sum[r] - sum[l - 1];
}
___________________________________________________________

"SPARSE TABLE"
build -> O(NlogN)
query -> O(logN)
bir aralıktaki toplam, max, min , ebob için kullanabilirsin.

ST[x][i] : answer the segment between [x, x + 2^i)

//Toplam sorgusu icin kurulmus Sparse Table Yapisi
void build() {
	for (int i = 1 ; i <= n ; i++) { // ilk satır 2^0 = 1 olduğu için dizinin kendisi.
		ST[i][0] = a[i];
	}
	for (int i = 1 ; i <= LOG ; i++)
		for (int j = 1 ; j <= n ; j++) {
			// [i,i+2^(j)] araliginin cevabi
			// [i,i+2^(j - 1) - 1] araligi ile [i+2^(j - 1),i+2^j] araliginin cevaplarinin birlesmesiyle elde edilir
			ST[i][j] = ST[i][j - 1] + ST[i + (1 « (j - 1))][j - 1];
		}

	return;
}

//toplam sorgusu
int query(int l,int r) {

	int res = 0;
	for (int i = LOG ; i >= 0 ; i-) {
		// her seferinde uzunlugu r - l + 1 gecmeyecek en buyuk araligin cevabi ekleyip
		// l'i o araligin sonuna cekiyoruz.
		if (l + (1 « i) <= r) {
			res += ST[l][i];
			l += (1 « i);
		}
	}

	return res;
}

// Min element between index l and r
int RMQ(int l,int r) {
	// log dizisinde her sayinin log2 degerleri sakldir.
	int j = log[r - l + 1];
	return min(ST[l][j], ST[r - (1 « j) + 1][j]);
}
__________________________________________________________________________________________________

"FENWICK TREE" ( Binary Indexed Tree)

Only can be used for cumulative operation (sum etc.)
Cannot be used with non-invertible operations (max, min etc.)
Eleman veya aralık guncellemeye olanak sağlar
build -> O(nlogn)
update -> O(logn)
query -> O(logn)

int n,tree[N],a[N];

void add(int val,int x) { // x indeksli elemanin degerini val degeri kadar artirir.
	while(x <= n) {
		tree[x] += val;
		x += x & (-x);
	}
}

void build() {
	for (int i = 1 ; i <= n ; i++)
		add(a[i],i);
}

int sum(int x) { // 1 indeksli elemandan x indeksli elemana
	int res = 0; // kadar olan sayilarin toplamini verir.
	while(x >= 1) {
		res += tree[x];
		x -= x & (-x);
	}
	return res;
}

int query(int l,int r) { // [l,r] araligindaki elemanlarin toplamini verir.
	return sum(r) - sum(l - 1);
}

"Aralık guncelleme için trick"
a -> main array
b -> define an array b such that a is prefixsum array of b. ( a[i] = sum of b[1].. b[i] )
build fenwick for array "b"

void build() {
	for (int i = 1 ; i <= n ; i++)
		b[i] = a[i] - a[i - 1]; // b dizisini olusturuyoruz.

	for (int i = 1 ; i <= n ; i++)
		add(b[i],i); // b dizisi uzerine fenwick tree kuruyoruz.
}

// l-r aralığındaki tum sayıları x kadar artır
void update(int l,int r,int x) {
	add(x,l); 		// L den sona kadar a nın elemanlarını x artırır
	add(-x,r + 1); 	// Sondakileri artırmak istemiyoduk. So, r+1 den sona kadar olanları x kadar azalt
}
___________________________________________________________________________________

"BST"
The data value of EVERY node in a node's left subtree is less than node itself.
The data value of EVERY node in a node's right subtree is greater than node itself.
  
struct Node { 
    int data; 
    struct Node *left, *right; 
}; 
  
// A utility function to create a new BST node 
Node* newNode(int item) 
{ 
    Node* temp = new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// A utility function to do inorder traversal of BST 
void inorder(Node* root) 
{ 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 
  
/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int val) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) 
        return newNode(val); 
  
    /* Otherwise, recur down the tree */
    if (val < node->data) 
        node->left = insert(node->left, val); 
    else
        node->right = insert(node->right, val); 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
/* Given a binary search tree and a key, this function deletes the key and returns the new root */
Node* deleteNode(Node* root, int val) 
{ 
    // Base case 
    if (root == NULL) 
        return root; 
  
    // Recursive calls for ancestors of node to be deleted 
    if (root->data > val) { 
        root->left = deleteNode(root->left, val); 
        return root; 
    } 
    else if (root->dadta < val) { 
        root->right = deleteNode(root->right, val); 
        return root; 
    } 
  
    // We reach here when root is the node to be deleted. 
  
    // If one of the children is empty 
    if (root->left == NULL) { 
        Node* temp = root->right; 
        delete root; 
        return temp; 
    } 
    else if (root->right == NULL) { 
        Node* temp = root->left; 
        delete root; 
        return temp; 
    } 
  
    // If both children exist 
    else { 
  
        Node* succParent = root->right; 
          
        // Find successor 
        Node *succ = root->right; 
        while (succ->left != NULL) { 
            succParent = succ; 
            succ = succ->left; 
        } 
  
        // Delete successor.  
        // Since successor is always left child of its parent 
        // we can safely make successor's right right child as left of its parent. 
        succParent->left = succ->right; 
  
        // Copy Successor Data to root 
        root->data = succ->data; 
  
        // Delete Successor and return root 
        delete succ;          
        return root; 
    } 
} 
  
// Driver Program to test above functions 
int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    Node* root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
  
    printf("\nDelete 20\n"); 
    root = deleteNode(root, 20); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 30\n"); 
    root = deleteNode(root, 30); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 50\n"); 
    root = deleteNode(root, 50); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    return 0; 
} 

Inorder traversal of the given tree 
20 30 40 50 60 70 80 
Delete 20
Inorder traversal of the modified tree 
30 40 50 60 70 80 
Delete 30
Inorder traversal of the modified tree 
40 50 60 70 80 
Delete 50
Inorder traversal of the modified tree 
40 60 70 80

_________________________________________________________________________________________________________________

"TREAP" = Tree + Heeap : Self Balancing Binary Search Tree 

Every node has key, priority
 - parent priority is higher than its children (Heap) // random assigned
 - all left node keys are lower than all right node keys (BST) 
 
 //Geeksforgeeks implementation
 
	struct TreapNode 
	{ 
		int key, priority; 
		TreapNode *left, *right; 
	}; 
	
	TreapNode* newNode(int key) 
	{ 
		TreapNode* temp = new TreapNode; 
		temp->key = key; 
		temp->priority = rand()%100; 
		temp->left = temp->right = NULL; 
		return temp; 
	} 
	
	// A utility function to print tree 
	void inorder(TreapNode* root) 
	{ 
		if (root) 
		{ 
		    inorder(root->left); 
		    cout << "key: "<< root->key << " | priority: %d "
		        << root->priority; 
		    if (root->left) 
		        cout << " | left child: " << root->left->key; 
		    if (root->right) 
		        cout << " | right child: " << root->right->key; 
		    cout << endl; 
		    inorder(root->right); 
		} 
	} 	

// Rotations
 T1, T2 and T3 are subtrees of the tree rooted with y (on left side) or x (on right side) 
 
                y                               x 
               / \     Right Rotation          /  \ 
              x   T3   – – – – – – – >        T1   y 
             / \       < - - - - - - -            / \ 
            T1  T2     Left Rotation            T2  T3 
  
   
	TreapNode *rightRotate(TreapNode *y) 
	{ 
		TreapNode *x = y->left,  *T2 = x->right; 
	  
		// Perform rotation 
		x->right = y; 
		y->left = T2; 
	  
		// Return new root 
		return x; 
	} 

	TreapNode *leftRotate(TreapNode *x) 
	{ 
		TreapNode *y = x->right, *T2 = y->left; 
	  
		// Perform rotation 
		y->left = x; 
		x->right = T2; 
	  
		// Return new root 
		return y; 
	} 
 
// search(x) ------------------------------------------------------------
1) Perform standard BST Search to find x.

	TreapNode* search(TreapNode* root, int key) 
	{ 
		// Base Cases: root is null or key is present at root 
		if (root == NULL || root->key == key) 
		   return root; 
		  
		// Key is greater than root's key 
		if (root->key < key) 
		   return search(root->right, key); 
	   
		// Key is smaller than root's key 
		return search(root->left, key); 
	} 
 
// Insert(x): -------------------------------------------------------------------------
1) Create new node with key equals to x, value equals to a random value.
2) Perform standard BST insert.
3) Use rotations to make sure that inserted node's priority follows max heap property.

	TreapNode* insert(TreapNode* root, int key) 
	{ 
		// If root is NULL, create a new node and return it 
		if (!root) 
		    return newNode(key); 
	  
		// If key is smaller than root 
		if (key <= root->key) 
		{ 
		    // Insert in left subtree 
		    root->left = insert(root->left, key); 
	  
		    // Fix Heap property if it is violated 
		    if (root->left->priority > root->priority) 
		        root = rightRotate(root); 
		} 
		else  // If key is greater 
		{ 
		    // Insert in right subtree 
		    root->right = insert(root->right, key); 
	  
		    // Fix Heap property if it is violated 
		    if (root->right->priority > root->priority) 
		        root = leftRotate(root); 
		} 
		return root; 
	} 
	
	
// Delete(x): -----------------------------------------------------------------
1) If node is a leaf, erase it.
2) If node has one child null and other as non-null, replace node with the non-empty child.
3) If node has both children as non-null, find max of left and right children.
  a) If priority of right child is greater, perform left rotation at node
  b) If priority of left child is greater, perform right rotation at node.
 
	TreapNode* deleteNode(TreapNode* root, int key) 
	{ 
		if (root == NULL) 
		    return root; 
	  
		if (key < root->key) 
		    root->left = deleteNode(root->left, key); 
		else if (key > root->key) 
		    root->right = deleteNode(root->right, key); 
	  
		// IF KEY IS AT ROOT ----
	  
		// If left is NULL 
		else if (root->left == NULL) 
		{ 
		    TreapNode *temp = root->right; 
		    delete(root); 
		    root = temp;  // Make right child as root 
		} 
	  
		// If Right is NULL 
		else if (root->right == NULL) 
		{ 
		    TreapNode *temp = root->left; 
		    delete(root); 
		    root = temp;  // Make left child as root 
		} 
	  
		// If key is at root and both left and right are not NULL 
		else if (root->left->priority < root->right->priority) 
		{ 
		    root = leftRotate(root); 
		    root->left = deleteNode(root->left, key); 
		} 
		else
		{ 
		    root = rightRotate(root); 
		    root->right = deleteNode(root->right, key); 
		} 
	  
		return root; 
	} 

















