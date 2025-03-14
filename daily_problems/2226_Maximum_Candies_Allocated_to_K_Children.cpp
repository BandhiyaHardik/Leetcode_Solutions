class Solution {
public:
    bool canDistr(vector<int>& candies, int mid, long long k) {
        int n = candies.size();

        for(int i = 0; i < n; i++) {
            k -= candies[i]/mid;

            if(k <= 0) {
                return true;
            }
        }

        return k <= 0;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int maxC = 0;
        long long total = 0;
        for(int i = 0; i < n; i++) {
            total += candies[i];
            maxC = max(maxC, candies[i]);
        }

        if(total < k) {
            return 0;
        }

        int l = 1;
        int r = maxC;
        int result = 0;
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(canDistr(candies, mid, k)) {
                result = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return result;
    }
};
