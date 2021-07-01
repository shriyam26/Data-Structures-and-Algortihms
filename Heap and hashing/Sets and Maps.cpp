Differences and similarities between set and map:-

set and map in STL are similar in the sense that they both use Red Black Tree (A self balancing BST). Note that the time complexities of search, insert and delete are O(Log n). 
Differences: 
The difference is set is used to store only keys while map is used to store key value pairs. 
For example consider in the problem of printing sorted distinct elements, we use set as there is value needed for a key. While if we change the problem to print frequencies of distinct sorted elements, we use map. We need map to store array values as key and frequencies as value.

//The only difference between set and map is that one is to store only keys, other stores key value pairs.

// CPP program to demonstrate working of set
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    set<int> s1;
    s1.insert(2);
    s1.insert(5);
    s1.insert(3);
    s1.insert(6);
 
    cout << "Elements in set:\n";
    for (auto it : s1)
        cout << it << " "; // Sorted
 
    return 0;
}

Output: 
Elements in set:
2 3 5 6

// CPP program to demonstrate working of map
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    map<int, int> m;
	//There are three ways to form a key value pair
 
    m[1] = 2; // Insertion by indexing
 
    // Direct pair insertion
    m.insert({ 4, 5 });
 
    // Insertion of pair by make_pair
    m.insert(make_pair(8, 5));
 
    cout << "Elements in map:\n";
    for (auto it : m)
        cout << "[ " << it.first << ", "
             << it.second << "]\n"; // Sorted
 
    return 0;
}
Output: 
Elements in map:
[ 1, 2]
[ 4, 5]
[ 8, 5]	

Variations of set and map: 
Set and Map, both stores unique values and sorted values as well. But If we don’t have such a requirement, we use multiset/multimap and unordered_set/unordered_map. 
Multimap/Multiset : It doesn’t allow elements to stored by indexing. 	
unordered_set/unordered_map: 


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


Same difference for ordered/unordered set.

Use std::map when =>
You need ordered data.
You would have to print/access the data (in sorted order).
You need predecessor/successor of elements.

Use std::unordered_map when =>
You need to keep count of some data (Example – strings) and no ordering is required.
You need single element access i.e. no traversal.
																			