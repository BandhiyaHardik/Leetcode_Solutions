class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1)
            return 1;
        
        int i = 1;
        int j = n;
        
        int frontSum = 1;
        int backSum  = n;

        
        while(i < j) {
            
            if(frontSum < backSum) {
                i++;
                frontSum += i;
            } else {
                j--;
                backSum += j;
            }

        }
        return frontSum == backSum ? i : -1;
    }
};