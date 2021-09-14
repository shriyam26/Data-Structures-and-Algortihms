//Clone a Binary Tree with Random Pointers in O(1) space

       P                     P
      / \                   / 
     /   \                 /   
    A     B               cP    
   /       \             / \  
  /         \           /   \ 
 X           Z         A     B    
                      /     / 
                     cA    cB
                    /        \ 
                   X          Z
                  /          /     
                 cX        cZ      
				 
				 
class Solution{
  public:
	// This bascially makes all new nodes to the left of the original node
	// so the series becomes old node then new node then old then new and so on
    Node* copyNodes(Node* root){
        if(!root) return root;
        Node* l = root->left;
        Node* r = root->right;
        root->left = new Node(root->data);
        root->right = nullptr;
        root->left->left = copyNodes(l);
        root->left->right = copyNodes(r);
        return root;
    }
    
	// here I connect all the random nodes (as the old nodes points to the random old nodes) and the new copy of these nodes lie on the left of each node.
    // so we just connect them. (root->left->random = root->random->left)
    void copyRandom(Node* root){
        if(!root) return;
        if(root->random) 
			root->left->random = root->random->left;
        copyRandom(root->left->left);
        copyRandom(root->left->right);
    }
    
	// here we detach the new formed tree from the original tree
    Node* separateNodes(Node* root){
        if(!root) return nullptr;
        Node* cloneRoot = root->left;
        root->left = cloneRoot->left;
        root->right = cloneRoot->right;
        cloneRoot->left = separateNodes(cloneRoot->left);
        cloneRoot->right = separateNodes(cloneRoot->right);
        return cloneRoot;
    }
    
    Node* cloneTree(Node* root){
        root = copyNodes(root);
        copyRandom(root);
        return separateNodes(root);
    }
};


//Clone a Binary Tree with Random Pointers in O(n) space

class Solution{
  public:
    Node* copyLeftRightNodes(Node* root, unordered_map<Node*, Node*> &mp){
        if(!root) return nullptr;
        Node* clone = new Node(root->data);
        mp[root] = clone;
        clone->left = copyLeftRightNodes(root->left, mp);
        clone->right = copyLeftRightNodes(root->right, mp);
        return clone;
    }
    
    void copyRandom(Node* root, Node* clone, unordered_map<Node*, Node*> &mp){
        if(!clone) return;
        clone->random = mp[root->random];
        copyRandom(root->left, clone->left, mp);
        copyRandom(root->right, clone->right, mp);
    }
    
    Node* cloneTree(Node* root){
        if(!root) return nullptr;
        unordered_map<Node*, Node*> mp;
        Node* cloneRoot = copyLeftRightNodes(root, mp);
        copyRandom(root, cloneRoot, mp);
        return cloneRoot;
    }
};