class Solution {
public: 
    bool checkValidString(string s) {
        stack<int> openSt;
        stack<int> asterisksSt;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(') {
                openSt.push(i);
            } else if (ch == '*') {
                asterisksSt.push(i);
            } else {
                if (!openSt.empty()) {
                    openSt.pop();
                } else if (!asterisksSt.empty()) {
                    asterisksSt.pop();
                } else {
                    return false;
                }
            }
        }

        while (!openSt.empty() && !asterisksSt.empty()) {
            if (openSt.top() > asterisksSt.top()) {
                return false;
            }
            openSt.pop();
            asterisksSt.pop();
        }

        return openSt.empty();
    }
};