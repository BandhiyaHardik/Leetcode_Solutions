class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        //intitial altitude is 0
        int prefixSum = 0, ans = 0;

        for(int i=0; i<gain.size(); i++){
            prefixSum += gain[i];

            //update when getting higher altitude
            if(prefixSum> ans) ans = prefixSum;
        }

        return ans;
    }
};