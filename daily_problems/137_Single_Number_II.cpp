class Solution {
public:
    int singleNumber(vector<int>& nums) {

        if(nums.size()<3) 
            return nums[0];

        sort(nums.begin(), nums.end());

        if(nums[0] != nums[1]) 
            return nums[0];

        for(int i=1; i<nums.size()-1; i++) {
            if(nums[i-1] != nums[i] && nums[i] != nums[i+1])
                return nums[i];
        }

        return nums[nums.size()-1];
    }
};class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int left=0;
        int cnt=0;
        long long prod=1;
        for(int right=0;right<n;right++){
            prod*=a[right];
            while(prod>=k&&left<n){
                prod/=a[left];
                left++;
            }
            if(prod<k)cnt+=right-left+1;
        }
        return cnt;
    }
};