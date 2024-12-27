class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int result = 0;

        int max_till_now = values[0]+0;

        for(int j = 1; j < n; j++) {
            int x = values[j]-j;
            int y = max_till_now;

            result = max(result, x+y);

            max_till_now = max(max_till_now, values[j]+j);
        }

        return result;
    }
};