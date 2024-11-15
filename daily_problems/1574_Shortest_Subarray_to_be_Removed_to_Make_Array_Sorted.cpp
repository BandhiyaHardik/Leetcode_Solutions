class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        int j = n-1;
        while(j > 0 && arr[j] >= arr[j-1]) {
            j--;
        }

        int i = 0;
        int result = j;

        while(i < j && (i == 0 || arr[i] >= arr[i-1])) {

            while(j < n && arr[i] > arr[j]) {
                j++;
            }

            result = min(result, j - i - 1);
            i++;
        }

        return result;

    }
};
