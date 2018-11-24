// TRIE

struct TrieNode
{
     struct TrieNode *children[ALPHABET_SIZE];     
     bool end;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *addNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
    pNode->end = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++){
        pNode->children[i] = NULL;
 	}
 	
    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]){
            pCrawl->children[index] = addNode();
        }
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->end = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]){
            return false;
        }    
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl != NULL && pCrawl->end);
}


// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string words[] = {"the", "a", "there","answer", "any", "by","bye", "their" };
    int n = sizeof(words)/sizeof(words[0]);
 
    struct TrieNode *root = addNode();
 
    // Construct trie
    for (int i = 0; i < n; i++){
        insert(root, words[i]);
    }    
 
    // Search for different keys
    search(root, "the") ? cout << "Yes\n" :  cout << "No\n";
    search(root, "these")? cout << "Yes\n" : cout << "No\n";
    return 0;
}









