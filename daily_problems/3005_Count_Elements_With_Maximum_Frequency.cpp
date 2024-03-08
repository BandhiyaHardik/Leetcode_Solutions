class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> arr(101);
        
        int maxFreq = 0;
        
        for(int &num : nums) {
            arr[num]++;
            maxFreq = max(maxFreq, arr[num]);
        }
        
        return count(arr.begin(), arr.end(), maxFreq)*maxFreq;
    }
};
