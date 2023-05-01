class Solution {
public:
    double average(vector<int>& salary) {
        double total = 0;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<salary.size();i++){
            total+=salary[i];
            mini=min(mini,salary[i]);
            maxi=max(maxi,salary[i]);
        }
        total-=(mini+maxi);
        return total/(salary.size()-2);
    }
};