class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();

        vector<int> maxRight(n);

        maxRight[n-1] = n-1;
        for(int i = n-2; i >= 0; i--) {
            int rightMaxIdx = maxRight[i+1];
            int rightMaxElement = s[rightMaxIdx];

            maxRight[i] = (s[i] > rightMaxElement) ? i : rightMaxIdx;
        }

        for(int i = 0; i < n; i++) {
            int maxRightIdx = maxRight[i];
            int maxRightElement = s[maxRightIdx];
            if(s[i] < maxRightElement) {
                swap(s[i], s[maxRightIdx]);
                return stoi(s);
            }
        }

        return num;
    }
};
