class Solution {
public:
    long long zeroFilledSubarray(vector<int>& n) {

        long long int ans = 0, cnt = 0;
        for(int x: n){
            if(x)
             cnt=0;
            else 
                cnt++;
            ans+=cnt;
        }
        return ans;
    }
};