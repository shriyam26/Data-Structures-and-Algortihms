Difference : 

                  | map             | unordered_map
---------------------------------------------------------
Ordering        | increasing  order   | no ordering
                | (by default)        |

Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |  

search time     | log(n)              | O(1) -> Average 
                |                     | O(n) -> Worst Case

Insertion time  | log(n) + Rebalance  | Same as search
                      
Deletion time   | log(n) + Rebalance  | Same as search


=> map has better security as if hackers preditc the hash function in unordered map correctly, then our data can be accessed.
=> std::map and std::set are extremely similar. They both have a sorted collection of unique keys. Additionally, map has a value associated with each key.
For example consider in the problem of printing sorted distinct elements, we use set as there is value needed for a key. While if we change the problem to print frequencies of distinct sorted elements, we use map

Advantages of BST over hash table:-

Hash Table supports following operations in Θ(1) time.
1) Search
2) Insert
3) Delete

The time complexity of above operations in a self-balancing Binary Search Tree (BST) (like Red-Black Tree, AVL Tree, Splay Tree, etc) is O(Logn).

So Hash Table seems to beating BST in all common operations. When should we prefer BST over Hash Tables, what are advantages. Following are some important points in favor of BSTs.

1. We can get all keys in sorted order by just doing Inorder Traversal of BST. This is not a natural operation in Hash Tables and requires extra efforts.
2. Doing order statistics, finding closest lower and greater elements, doing range queries are easy to do with BSTs. Like sorting, these operations are not a natural operation with Hash Tables.
3. BSTs are easy to implement compared to hashing, we can easily implement our own customized BST. To implement Hashing, we generally rely on libraries provided by programming languages.
4. With Self-Balancing BSTs, all operations are guaranteed to work in O(Logn) time. But with Hashing, Θ(1) is average time and some particular operations may be costly, especially when table resizing happens.
5. Designing a good hash table requires intimate knowledge of the context it which it will be used. Should it use open addressing, or linked chaining? What levels of load should it accept before resizing? Should it use an expensive hash that avoids collisions, or one that is rough and fast?
Since the STL can't anticipate which is the best choice for your application, the default needs to be more flexible. Trees "just work" and scale nicely.


Should maps always use trees?

Another possible maps implementation would be a sorted vector (insertion sort) and binary search. This would work well for containers which aren't modified often but are queried frequently



When used with a hashmap, hash functions have two important properties. The first is stability. The hash function must be stable. Given the same key, your hash function must return the same answer. If it doesn’t you will not be able to find things you put into the map.

The second property is good distribution. Given two near identical keys, the result should be wildly different. This is important for two reasons. Firstly, as we’ll see, values in a hashmap should be distributed evenly across buckets, otherwise the access time is not O(1). Secondly as the user can control some of the aspects of the input to the hash function, they may be able to control the output of the hash function, leading to poor distribution which has been a DDoS vector for some languages. This property is also known as collision resistance.

That's wy generally hash tables have prime number as size, as it avoids collision and values are not clustered in small buckets, instead they are distributed which is a good thing for hash table.