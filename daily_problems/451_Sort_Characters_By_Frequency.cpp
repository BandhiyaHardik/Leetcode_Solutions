class Solution {
public:
    typedef pair<char, int> P;
    struct comp {
        bool operator()(P &p1, P &p2) {
            return p1.second<p2.second; 
        }
    };
    
    string frequencySort(string s) {
        priority_queue<P, vector<P>, comp> pq;
        
        unordered_map<char, int> mp;
        for(char &ch : s) {
            mp[ch]++;
        }
        
        for(auto &it : mp) {
            pq.push({it.first, it.second});
        }
        
        string result = "";
        
        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();
            
            result += string(temp.second, temp.first);
        }
        return result;
    }
};