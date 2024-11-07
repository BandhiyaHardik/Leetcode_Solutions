class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(24, 0);

        int result = 0;

        for(int i = 0; i < 24; i++) {

            for(int &num : candidates) {
                if((num & (1 << i)) != 0) {
                    count[i]++;
                }
            }

            result = max(result, count[i]);

        }

        return result;
    }
};
