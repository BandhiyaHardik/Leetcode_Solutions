class Solution {
public: 
    int M = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.length();

        vector<int> mp(26, 0);

        for(char &ch : s) {
            mp[ch - 'a']++;
        }

        for(int count = 1; count <= t; count++) {
            vector<int> temp(26, 0);

            for(int i = 0; i < 26; i++) {
                char ch  = i + 'a';
                int freq = mp[i];

                if(ch != 'z') {
                    temp[(ch+1) - 'a'] = (temp[(ch+1) - 'a'] + freq) % M;
                } else {
                    temp['a' - 'a'] = (temp['a' - 'a'] + freq) % M;
                    temp['b' - 'a'] = (temp['b' - 'a'] + freq) % M;
                }
            }

            mp = move(temp);
        }

        int result = 0;
        for(int i = 0; i < 26; i++) {
            result = (result + mp[i]) % M;
        }

        return result;
    }
};