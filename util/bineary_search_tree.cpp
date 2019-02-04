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


