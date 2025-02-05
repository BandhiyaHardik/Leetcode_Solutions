class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();

        if(s1 == s2) {
            return true;
        }

        int diffs = 0;

        int freq1[26] = {0};
        int freq2[26] = {0};

        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                diffs++;
            }

            if(diffs > 2)
                return false;

            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;

    }
};