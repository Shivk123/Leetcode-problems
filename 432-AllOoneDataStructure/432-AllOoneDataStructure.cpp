// Last updated: 5/28/2025, 9:54:57 PM
class AllOne {
private:
unordered_map<string,int> keys;
set<pair<int,string>> order;

public:
    AllOne() {
        
    }
    
    void inc(string key) {
        int n = keys[key];
        keys[key]++;
        order.erase({n, key});
        order.insert({n+1, key});
    }
    
    void dec(string key) {
        int n = keys[key];
        keys[key]--;
        order.erase({n, key});
        if (n>1) order.insert({n-1, key});
        else keys.erase(key);
    }
    
    string getMaxKey() {
        if (!order.empty()) return order.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        if (!order.empty()) return order.begin()->second;
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */