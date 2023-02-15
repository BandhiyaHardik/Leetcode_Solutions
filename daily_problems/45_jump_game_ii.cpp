class Solution {
public:
    int jump(vector<int>& nums) {
        int maxSofar =0;
        int currentMax = 0;
        int jump=0;

        for(int i=0;i<nums.size()-1;i++){
            maxSofar = max(maxSofar,i+nums[i]);

            if(i == currentMax){
                jump++;
                currentMax = maxSofar;
            }
        }
        return jump;
    }
};