class LRUCache {
public:
    // Brute forcce code
    vector<pair<int, int>>cache;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        for(int i = 0 ; i < cache.size(); i++){
            if(cache[i].first == key){  // if found then print and remove from and push into last 
                int val = cache[i].second;
                auto temp = cache[i]; // push current one to the end first delete
                cache.erase(begin(cache) + i);
                cache.push_back(temp);
                return val;
            }
        }
        return -1 ; // not present
    }
    
    void put(int key, int value) {
        for(int i = 0 ; i < cache.size(); i++){
                if(cache[i].first == key){
                    cache.erase(begin(cache) + i);
                    cache.push_back({key , value});
                    return ;
                }
        }
        if(cache.size() == n){ // if full first delete first and then push new one
            cache.erase(cache.begin());
            cache.push_back({key , value});
        } else {  // push new one in the end 
            cache.push_back({key , value});
            3598856
        }
    }
};
