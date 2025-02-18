class Solution {
public:
    bool matchesPattern(string &num, string &pattern) {
        for(int i = 0; i < pattern.length(); i++) {
            if((pattern[i] == 'I' && num[i] > num[i+1]) ||
                (pattern[i] == 'D' && num[i] < num[i+1])) {
                return false;
            }
        }

        return true;
    }

    string smallestNumber(string pattern) {
        int n = pattern.length();
        string num = "";
        
        for(int i = 1; i <= n+1; i++) {
            num.push_back(i + '0'); 
        }

        while(!matchesPattern(num, pattern)) {
            next_permutation(begin(num), end(num));
        }

        return num;

    }
};