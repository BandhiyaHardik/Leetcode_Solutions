class RandomizedSet {
public:

    vector<int> vec;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())
            return false;
        
        vec.push_back(val);
        mp[val] = vec.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())
            return false;
        
        int idx       = mp[val];
        int temp      = vec.back();
        vec.back()    = val;
        vec[idx]      = temp;
        mp[temp]      = idx;
        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand()%vec.size();
        return vec[idx];
    }
};
