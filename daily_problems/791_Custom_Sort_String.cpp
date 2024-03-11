class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> index(26, -1);
        
        for(int i = 0; i<order.length(); i++)
            index[order[i]-'a'] = i;
        
        
        auto lambda = [&index](char &ch1, char &ch2) {
            return index[ch1-'a'] < index[ch2-'a'];
        };
        
        sort(begin(str), end(str), lambda);
        return str;
        
    }
};