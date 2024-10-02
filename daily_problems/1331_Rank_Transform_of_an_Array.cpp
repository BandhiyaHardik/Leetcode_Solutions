class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> sortedArr = arr;
        
        sort(sortedArr.begin(), sortedArr.end());
        
        unordered_map<int, int> rankMap;
        int rank = 1;

        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }
        
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = rankMap[arr[i]];
        }
        
        return arr;
    }
};
