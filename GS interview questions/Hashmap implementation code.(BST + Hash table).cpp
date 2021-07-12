/*
Hashtable implementation of Hashmap
*/

class Item{
public:
    int key;
    int val;
    Item(int k, int v){
        key = k; 
        val = v;
    }

};
class MyHashMap {
public:
    /** Initialize your data structure here. */
    int len = 1007;
    vector<list<Item> > mp;
    MyHashMap() {
        mp.resize(len);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashVal = key % len;
        if(mp[hashVal].empty()){
            Item Pair(key, value);
            mp[hashVal].push_back(Pair);
        }
        else{
            for(auto it = mp[hashVal].begin(); it != mp[hashVal].end(); it++){
                auto Item = *it;
                if(Item.key == key){
                    it->val = value;
                    return;
                }
            }
            Item Pair(key, value);
            mp[hashVal].push_back(Pair);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashVal = key % len;
        if(mp[hashVal].empty()){
            return -1;
        }
        for(auto it = mp[hashVal].begin(); it != mp[hashVal].end(); it++){
            auto Item = *it;
            if(Item.key == key){
                return (it->val);
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashVal = key % len;
        if(mp[hashVal].empty()){
            return;
        }
        for(auto it = mp[hashVal].begin(); it != mp[hashVal].end(); it++){
            auto Item = *it;
            if(Item.key == key){
                it->val = -1;
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
 
/*
BST implementation of Hashmap
*/
 
class Node{
    int key;
    int value;
    Node* left;
    Node* right;
    Node(int k, int v){
        key = k;
        value = v;
    }
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    int size = 1007;
    Node* bucket[];
    
    MyHashMap() {
        bucket = new Node[size];    
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % size;
        Node* root = bucket[index];
        root = insert(root, key, value);
        bucket[index] = root;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key % size;
        Node* root = bucket[index];
        return search(root, key);
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        put(key, -1);
    }
    
private:
    
    Node* insert(Node* root, int key, int value){
        if(root == NULL){
            return new Node(key, value);
        }
        if(key > root->key){
            root->right = insert(root->right, key, value);
        }
        else if(key < root->key){
            root->left = insert(root->left, key, value);
        }
        else if(key == root->key){
            root->value = value;
        }
    }
    
    Node search(Node root, int key){
        if(root == NULL){
            return -1;
        }
        if(key > root.key){
            root->right = search(root->right, key);
        }
        else if(key < root->key){
            root->left = search(root->left, key);
        }
        else if(key == root->key){
            return root->val;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */