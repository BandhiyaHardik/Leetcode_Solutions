class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
    
            int result = 0;
    
            int length = 1;
            int last   = colors[0];

            for(int i = 1; i < n; i++) {
                if(colors[i] == last) {
                    length = 1;
                    last = colors[i];
                    continue;
                }
    
                length++;
    
                if(length >= k) {
                    result++;
                }
    
                last = colors[i];
            }

            for(int i = 0; i < k-1; i++) {
                if(colors[i] == last) {
                    length = 1;
                    last = colors[i];
                    break;
                }
    
                length++;
    
                if(length >= k) {
                    result++;
                }
    
                last = colors[i];
            }
    
            return result;
    
    
        }
    };