class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shiftCount(n + 1, 0);

        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int value = (direction == 1) ? 1 : -1;
            shiftCount[start] += value;
            shiftCount[end + 1] -= value;
        }

        int netShift = 0;
        for (int i = 0; i < n; ++i) {
            netShift += shiftCount[i];
            netShift %= 26;
            int newChar = (s[i] - 'a' + netShift + 26) % 26;
            s[i] = 'a' + newChar;
        }

        return s;
    }
};
