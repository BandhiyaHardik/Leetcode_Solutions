class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();

        int maxOdd  = 0;
        int minEven = n+1;

        vector<int> vec(26, 0);
        for(char &ch : s) {
            vec[ch-'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(vec[i] == 0)
                continue;

            if(vec[i]%2 == 0) {
                minEven = min(minEven, vec[i]);
            } else {
                maxOdd = max(maxOdd, vec[i]);
            }
        }

        return maxOdd - minEven;
    }
};