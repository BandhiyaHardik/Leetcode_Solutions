class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> st;
        int n = digits.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(i == j || j == k || i == k) {
                        continue;
                    }

                    int num = digits[i]*100 + digits[j] * 10 + digits[k];

                    if(num >= 100 && num%2 == 0) {
                        st.insert(num);
                    }
                }
            }
        }

        vector<int> result(begin(st), end(st));
        sort(begin(result), end(result));
        return result;
    }
};
