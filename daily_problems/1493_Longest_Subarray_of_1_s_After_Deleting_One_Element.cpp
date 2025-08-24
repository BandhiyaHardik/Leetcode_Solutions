class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int start=0,end=0,n=nums.size();

        int ans=0;

        int skip=0;

        while(end<n){

            if(nums[end]==0)
                skip++;
            
            if(skip>1){
                skip-=nums[start]==0;
                start++;    
            }
            
            ans=max(ans,end-start);
            end++;
        }

        return ans;
    }
};