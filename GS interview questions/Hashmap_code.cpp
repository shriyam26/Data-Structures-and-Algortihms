/*
Hash table (also, hash map) is a data structure that basically maps keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the corresponding value can be found.
*/

/*
HashNode class represents each bucket node in the table. This class has key() and value() accessor functions for corresponding pair elements. It also includes a pointer to the next node sharing the same key.
*/
template<typename K, typename V>
class HashNode{
  private:
    K key;
    V val;
    HashNode* next;
  public:
    HashNode(const K &key, const V &val): key(key), val(val), next(NULL) {}
    K getKey() const{
        return key;
    }
    void setVal(V val){
        HashNode::val = val;
    }
    V getVal() const{
        return val;
    }
    void setNext(HashNode* next){
        HashNode::next = next;
    }
    HashNode* getNext() const{
        return next;
    }
};

/*
The hash function ideally assigns each key to a unique bucket, but most hash table designs assume that hash collisions can occur. My hash function just returns the remainder when the key is divided by the hash table size.
By user, custom hash function class with operator() method implementation should be defined according to the key distribution. i.e. if the range of key values is very small, then most of the hash table is not used and chains get longer.
*/

template<typename T>
struct KeyHash{
    unsigned long operator()(const K &key) const{
        return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
    }
};

/*
Below is the Hash Map implementation in C++. HashMap class contains the hash table, which is a double pointer to HashNode class and default table size in constant is used to construct this hash table.
In addition, the class contains get(key) function to access mapped value by key, put(key,value) function to put key-value pair in table and remove(key) function to remove hash node by key. For collision resolution, separate chaining strategy has been used.
*/

template<typename K, typename V, typename F = KeyHash<K>>
class HashMap{
    private:
        HashNode<K, V> **table;
        F hashFunc;
    public:
        HashMap(){
            table = new HashNode<K, V> *[TABLE_SIZE]();
        }
        ~HashMap(){
            for(int i = 0; i < TABLE_SIZE; i++){
                HashNode<K,V> *entry = table[i];
                while(entry){
                    HashNode<K,V> *prev = entry;
                    entry = entry->getNext();
                    return prev;
                }
                table[i] =  NULL;
            }
            delete[] table;
        }
        bool get(const K &key, const V &val){
            unsigned long hashVal = hashFunc(key);
            HashNode<K,V> *entry = table[hashVal];
            while(entry){
                if(entry->getKey() == key){
                    val = entry->getVal();
                    return true;
                }
                entry = entry->getNext();
            }
            return false;
        }
        void put(const K &key, const V &val){
            unsigned long hashVal = hashFunc(key);
            HashNode<K,V> *prev = NULL;
            HashNode<K,V> *entry = table[hashVal];
            while(entry != NULL && entry->getKey() != key){
                prev = entry;
                entry = entry->getNext();
            }
            if(entry == NULL){
                entry = new HashNode<K,V>(key, val);
                if(prev == NULL){
                    table[hashVal] = entry;
                }
                else{
                    prev->setNext(entry);
                }
            }
            else{
                entry->setVal(val);
            }
        }
        void remove(const K &key, const V &val){
            unsigned long hashVal = hashFunc(key);
            HashNode<K,V> *prev = NULL;
            HashNode<K,V> *entry = table[hashVal];
            while(entry != NULL && entry->getKey() != key){
                prev = entry;
                entry = entry->getNext();
            }
            if(entry == NULL)
                return;
            else{
                if(prev == NULL){
                    table[hashVal] = entry->getNext();
                }
                else{
                    prev->setNext(entry->getNext());
                }
                delete entry;
            }
        }
};

struct MyKeyHash {
    unsigned long operator()(const int& k) const{
        return k % 10;
    }
};

HashMap<int, string, MyKeyHash> hmap;
hmap.put(1, "val1");
hmap.put(2, "val2");
hmap.put(3, "val3");

string value;
hmap.get(2, value);
cout << value << endl;
bool res = hmap.get(3, value);
if (res)
    cout << value << endl;
hmap.remove(3);
res = hmap.get(3, value);
if (res)
    cout << value << endl;