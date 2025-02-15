class Solution {
public:
    bool check(int num, int currnum, int target) {
        if(num == 0) {
            return currnum == target;
        }
        
        return check(num / 10, currnum + num % 10, target) ||
               check(num / 100, currnum + num % 100, target) ||
               check(num / 1000, currnum + num % 1000, target) ||
               check(num / 10000, currnum + num % 10000, target);
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;
            if (check(squareNum, 0, currentNum)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};