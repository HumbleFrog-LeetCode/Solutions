class LRUCache {
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    int capacity;

    void refreshPosition(int key, int value) {
        cache.erase(mp[key]);
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)) {
            refreshPosition(key, (*mp[key]).second);
            return (*mp[key]).second;
        }
        else 
            return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key))
            refreshPosition(key, value);
        else {
            if(cache.size() == capacity) {
                mp.erase(cache.back().first);
                cache.pop_back();
            }
            cache.push_front({key, value});
            mp[key] = cache.begin();
        }    
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */