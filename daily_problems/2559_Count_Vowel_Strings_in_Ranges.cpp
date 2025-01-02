class Solution {
public:
    bool isVowel(char &ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int Q = queries.size();
        int N = words.size();

        vector<int> result(Q);

        vector<int> cumSum(N);
        int sum = 0;
        for(int i = 0; i < N; i++) {
            if(isVowel(words[i][0]) && isVowel(words[i].back())) {
                sum++;
            }

            cumSum[i] = sum;
        }

        for(int i = 0; i < Q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            result[i] = cumSum[r] - ((l > 0) ? cumSum[l-1] : 0);
        }

        return result;
    }
};