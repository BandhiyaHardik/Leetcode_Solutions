class Solution {
public:
    int minLength(string s) {
        
        while (s.find("AB") != -1 || s.find("CD") != -1) {
            if (s.find("AB") != -1) {
                
                s.erase(s.find("AB"), 2);
            } else if (s.find("CD") != -1) {
                
                s.erase(s.find("CD"), 2);
            }
        }

        return s.length();
    }
};
