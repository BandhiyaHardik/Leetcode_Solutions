class LRUCache {
public:
    int capacity;
    queue<int> used_history;

    unordered_map<int, int> q_counter;

    unordered_map<int, int> dict;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {

        if (dict.count(key)) {
            used_history.push(key);
            q_counter[key]++;
            return dict[key];
        }
        return -1;
    }

    void remove_lru() {
        while (!used_history.empty()) {
            int cur = used_history.front();

            used_history.pop();

            q_counter[cur]--;
            
            if (q_counter[cur] == 0) {
                dict.erase(cur);
                break;
            }
        }
    }


    void put(int key, int value) {

        used_history.push(key);
        q_counter[key]++;
        dict[key] = value;
        if (dict.size() > this->capacity) {
            remove_lru();
        }
    }
};
