class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int stream = 1;
        
        vector<string> result;
        
        int i = 0;
        while(i < target.size() && stream <= n) {
            result.push_back("Push");
            
            if(stream == target[i]) {
                i++;
            } else {
                result.push_back("Pop");
            }
            stream++;
        }
        
        return result;
    }
};