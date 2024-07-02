class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;

        for(int &num : nums1) {
            mp[num]++;
        }

        vector<int> result;
        for(int i = 0; i < nums2.size(); i++) {
            int num = nums2[i];

            if(mp[num] > 0) {
                mp[num]--;
                result.push_back(num);
            }
        }

        return result;

    }
};