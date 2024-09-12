class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st(begin(allowed), end(allowed));

        int count = 0;
        for(string &word : words) {
            bool allChar = true;

            for(char &ch : word) {
                if(!st.count(ch)) {
                    allChar = false;
                    break;
                }
            }

            count += allChar;
        }

        return count;
    }
};