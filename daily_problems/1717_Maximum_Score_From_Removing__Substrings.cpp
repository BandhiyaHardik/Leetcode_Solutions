class Solution {
public:
    int removeSubstr(string& s, char first, char second, int points) {
        stack<char> st;
        int score = 0;

        for (char ch : s) {
            if (!st.empty() && st.top() == first && ch == second) {
                st.pop();
                score += points;
            } else {
                st.push(ch);
            }
        }

        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return score;
    }

    int maximumGain(string s, int x, int y) {
        int totalScore = 0;

        if (x >= y) {
            totalScore += removeSubstr(s, 'a', 'b', x);
            totalScore += removeSubstr(s, 'b', 'a', y);
        } else {
            totalScore += removeSubstr(s, 'b', 'a', y);
            totalScore += removeSubstr(s, 'a', 'b', x);
        }

        return totalScore;
    }
};
