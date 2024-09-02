class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        long long totalChalkSum = 0;
        for(int &chalkReq : chalk) {
            totalChalkSum += chalkReq;
        }

        int remainChalk = k%totalChalkSum;

        for(int i = 0; i < n; i++) {
            if(remainChalk < chalk[i]) {
                return i;
            }

            remainChalk -= chalk[i];
        }

        return -1;
    }
};