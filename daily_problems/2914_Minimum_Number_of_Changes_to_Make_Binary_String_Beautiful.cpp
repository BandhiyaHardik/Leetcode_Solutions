class Solution {
public:
    int minChanges(string s) {
        char curr = s[0];

        int count = 0;
        int changes = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {

            if (s[i] == curr) {
                count++;
                continue;
            }

            if (count % 2 == 0) {
                count = 1;
            } else {
                count = 0;
                changes++;
            }
            
            curr = s[i];
        }

        return changes;
    }
};