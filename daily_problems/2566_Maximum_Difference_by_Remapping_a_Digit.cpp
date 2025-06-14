class Solution {
public:
    int minMaxDifference(int num) {
        string minNum = to_string(num);
        string maxNum = to_string(num);
        int n = minNum.length();

        char ch = ' ';
        for(int i = 0; i < n; i++) {
            if(maxNum[i] != '9') {
                ch = maxNum[i];
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if(maxNum[i] == ch) {
                maxNum[i] = '9';
            }
        }
        

        ch = minNum[0];
        for(int i = 0; i < n; i++) {
            if(minNum[i] == ch) {
                minNum[i] = '0';
            }
        }

        return stoi(maxNum) - stoi(minNum);

    }
};