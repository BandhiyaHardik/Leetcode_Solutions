class Solution {
public:
    bool canDistribute(int n, vector<int>& quantities, int x) {
        int storesNeeded = 0;
        for (int quantity : quantities) {
            storesNeeded += (quantity + x - 1) / x;
            if (storesNeeded > n) {
                return false;
            }
        }
        return storesNeeded <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canDistribute(n, quantities, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
