class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true) {
            int idx = s.find(part);

            if(idx == string::npos) {
                break;
            }

            s.erase(idx, part.length());
        }

        return s;
    }
};