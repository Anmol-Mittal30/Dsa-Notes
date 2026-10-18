class LFUCache
{
public:
    // TC -> get , put ->O(logn) , SC -> O(n)
    int cap;
    int size;
    unordered_map<int, list<vector<int>>::iterator> mp; // key -> address
    map<int, list<vector<int>>> freq;                   // counter -> {key , val , counter}

    void makeMostfrequentlyUsed(int key)
    {
        auto &vec = *(mp[key]);
        int val = vec[1];
        int f = vec[2];
        freq[f].erase(mp[key]); // mp[key] gives the addrs of that current node
        if (freq[f].empty())
            freq.erase(f);

        f++;                               // update the freq
        freq[f].push_front({key, val, f}); // update new f to new place
        mp[key] = freq[f].begin();         // new address update of new place
    }

    LFUCache(int capacity)
    {
        cap = capacity;
        size = 0;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1; // key not present

        auto vec = *mp[key]; // vec gives -> {key , val , counter}
        int val = vec[1];
        makeMostfrequentlyUsed(key); // update this freq of that key

        return val;
    }

    void put(int key, int value)
    {
        if (cap == 0)
            return;
        if (mp.find(key) != mp.end())
        {
            auto &vec = *mp[key];
            vec[1] = value; // key already exist so value update
            makeMostfrequentlyUsed(key);
            return;
        }
        else if (size < cap)
        {
            size++;
            // fresh value hai toh freq 1 hogi
            freq[1].push_front({key, value, 1});
            mp[key] = freq[1].begin();
        }
        else
        { // IF size full hai toh htana padega jiski freq km hai ;
            auto &f = freq.begin()->first;
            auto &kaun_sa_list = freq.begin()->second;
            int key_tobe_delete = kaun_sa_list.back()[0];
            kaun_sa_list.pop_back();
            if (kaun_sa_list.empty())
                freq.erase(f);
            freq[1].push_front({key, value, 1}); // push in the front
            mp.erase(key_tobe_delete);
            mp[key] = freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */