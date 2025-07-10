class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeArray;
        
        freeArray.push_back(startTime[0]);

        for(int i = 1; i < startTime.size(); i++) {
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }

        freeArray.push_back(eventTime - endTime[endTime.size()-1]);

        int n = freeArray.size();
        vector<int> maxRightFree(n, 0);
        vector<int> maxLeftFree(n, 0);
        for(int i = n-2; i >= 0; i--) {
            maxRightFree[i] = max(maxRightFree[i+1], freeArray[i+1]);
        }

        for(int i = 1; i < n; i++) {
            maxLeftFree[i] = max(maxLeftFree[i-1], freeArray[i-1]);
        }


        int result = 0;

        for(int i = 1; i < n; i++) {
            int currEventTime = endTime[i-1] - startTime[i-1];

            if(currEventTime <= max(maxLeftFree[i-1], maxRightFree[i])) {
                result = max(result, freeArray[i-1] + currEventTime + freeArray[i]);
            }

            result = max(result, freeArray[i-1] + freeArray[i]);
        }

        return result;

    }
};