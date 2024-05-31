class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_r = 0;

        for(int &num : nums) {
            xor_r ^= num;
        }

        int mask = (xor_r) & (-xor_r);

        int groupa = 0;
        int groupb = 0;

        for(int &num : nums) {
            if(num & mask) {
                groupa ^= num;
            } else {
                groupb ^= num;
            }
        }

        return {groupa, groupb};
    }
};