// class LRUCache {
// public:
//     // Brute forcce code
//     vector<pair<int, int>>cache;
//     int n;
//     LRUCache(int capacity) {
//         n = capacity;
//     }
    
//     int get(int key) {
//         for(int i = 0 ; i < cache.size(); i++){
//             if(cache[i].first == key){  // if found then print and remove from and push into last 
//                 int val = cache[i].second;
//                 auto temp = cache[i]; // push current one to the end first delete
//                 cache.erase(begin(cache) + i);
//                 cache.push_back(temp);
//                 return val;
//             }
//         }
//         return -1 ; // not present
//     }
    
//     void put(int key, int value) {
//         for(int i = 0 ; i < cache.size(); i++){
//                 if(cache[i].first == key){
//                     cache.erase(begin(cache) + i);
//                     cache.push_back({key , value});
//                     return ;
//                 }
//         }
//         if(cache.size() == n){ // if full first delete first and then push new one
//             cache.erase(cache.begin());
//             cache.push_back({key , value});
//         } else {  // push new one in the end 
//             cache.push_back({key , value});
//             3598856
//         }
//     }
// };


// Optimised code using doubly linked list and hash map


// LRU Cache — O(1) Get & Put
// Implemented an LRU (Least Recently Used) Cache using a doubly linked list and hash map. The doubly linked list maintains the usage order, while the map provides O(1) access to cache entries and their list iterators. Recently accessed or inserted keys are moved to the front, and the least recently used key is removed from the back when capacity is exceeded.

class LRUCache {
public:
    // when n < 0 means capacity is excedd so remove last eleemtn in doubly linked list 
    // Optimised using linked list 
    list<int>dll;   // doubly linked list
    map<int , pair<list<int>::iterator , int>> mp; // {key -> {add. value}}
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    void makeRecentlyUsed(int key){
        dll.erase(mp[key].first); 
        dll.push_front(key) ;    // now it will become new one
        mp[key].first = dll.begin(); // add will beccame new
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        makeRecentlyUsed(key);
        return mp[key].second; // gives the value
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makeRecentlyUsed(key);
            return ;
        } else{
            dll.push_front(key);
            mp[key] = {dll.begin() , value}; // become recently used
            n--;
        }

        if(n < 0){
            int key_tobe_delete = dll.back();
            mp.erase(key_tobe_delete);
            dll.pop_back();
            n++;
        }


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 // we can also solve by using sinlgy linked list also 