class Solution {
public:

    char kthCharacter(int k) {
        int idx = k-1;
        string result = "a";

        while(result.length() < k) {
            int n = result.length();
            for(int i = 0; i < n; i++) {
                char ch = result[i] == 'z' ? 'a' : result[i]+1;
                result.push_back(ch);
            }
        }

        return result[idx];
    }
};