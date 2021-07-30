Let’s first quickly go over what is cache. Computers have cache memory that temporarily stores the most frequently used data. It’s a great way to get the data that is used most often because the retrieval process is super fast. Computers also have memory but it’s more expensive to retrieve data from there. However, cache memory is limited in size and there needs to be a way to manage what data needs to be removed from the cache in order to store new data. That’s where LRU cache comes in. It’s a cache replacement algorithm that removes the least recently used data in order to make room for new data.

We are given total possible page numbers that can be referred. We are also given cache (or memory) size (Number of page frames that cache can hold at a time). The LRU caching scheme is to remove the least recently used frame when the cache is full and a new page is referenced which is not there in cache.

We can implement it with the help of a list and map.
1. map:- In this the page number is passed as key, and value is the node of doubly linked list.
2. list:- The maximum size of the queue will be equal to the total number of frames available (cache size). The most recently used pages will be near front end and least recently pages will be near the rear end. 

/* LRU Cache Implementation */

class LRUCache {
    int Capacity;
    list<pair<int,int>> dll;  // {key,value}
    unordered_map<int,list<pair<int,int>> :: iterator> mp;  // {key,iterator}
    
public:
    LRUCache(int capacity) {
        Capacity=capacity;
    }
    
    int get(int key) {
        
        if(mp.find(key)!=mp.end())
        {
            int value=(*mp[key]).second;              // updating it to make it MRU
            dll.erase(mp[key]);
            dll.push_front({key,value});   
            mp[key]=dll.begin();                    // since MRU is at head so iterator=dll.begin()
            return value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())           // if present then update it to make it MRU
        {  
            dll.erase(mp[key]);
            dll.push_front({key,value});
            mp[key]=dll.begin();
        }
        else {
            if(dll.size()<Capacity)                   // just insert
            {
                dll.push_front({key,value});
                mp[key]=dll.begin();
            }
            else {                                             // erase the LRU and make new page as MRU
                int victimKey=dll.back().first;
                dll.pop_back();
                mp.erase(victimKey);
                dll.push_front({key,value});
                mp[key]=dll.begin();
            }
        }
    }
};