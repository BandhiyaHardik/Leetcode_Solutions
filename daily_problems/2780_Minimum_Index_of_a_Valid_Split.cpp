class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        int maj   = -1;
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(count == 0) {
                maj = nums[i];
                count = 1;
            } else if(nums[i] == maj) {
                count++;
            } else {
                count--;
            }
        }

        int majCount = 0;
        for(int &num : nums) {
            if(num == maj) {
                majCount++;
            }
        }

        count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == maj) {
                count++;
            }

            int remainingCount = majCount - count;
            int n1 = i+1;
            int n2 = n-i-1;

            if(count*2 > n1 && remainingCount*2 > n2) {
                return i;
            }
        }


        return -1;

    }
};
