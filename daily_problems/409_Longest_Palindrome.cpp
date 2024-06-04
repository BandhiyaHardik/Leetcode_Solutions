class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_set<char> st;

        int result = 0;
        for(char &ch : s) {
            if(st.count(ch)) {
                st.erase(ch);
                result += 2;
            } else {
                st.insert(ch);
            }
        }

        if(!st.empty())
            result++;
        
        return result;
    }
};