class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();

        int teams = 0;

        for(int j = 1; j < n-1; j++) {

            int countSmallerLeft = 0;
            int countLargerLeft  = 0;
            int countSmallerRight = 0;
            int countLargerRight = 0;

            for(int i = 0; i < j; i++) {
                if(rating[i] < rating[j]) {
                    countSmallerLeft++;
                } else if(rating[i] > rating[j]) {
                    countLargerLeft++;
                }
            }

            for(int k = j+1; k < n; k++) {
                if(rating[j] < rating[k]) {
                    countLargerRight++;
                } else if(rating[j] > rating[k]) {
                    countSmallerRight++;
                }
            }

            teams += (countLargerLeft * countSmallerRight) + (countSmallerLeft * countLargerRight);


        }

        return teams;
    }
};