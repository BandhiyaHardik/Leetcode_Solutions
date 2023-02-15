class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int num_columns_to_delete = 0;
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] < strs[j - 1][i]) {
                    num_columns_to_delete++;
                    break;
                }
            }
        }
        return num_columns_to_delete;
    }
};