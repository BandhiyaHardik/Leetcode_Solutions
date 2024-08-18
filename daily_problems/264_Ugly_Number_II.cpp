class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> uglyNumbers(n);
        uglyNumbers[0] = 1;
        
        int p2 = 0, p3 = 0, p5 = 0;
        
        for (int i = 1; i < n; ++i) {

            int next2 = uglyNumbers[p2] * 2;
            int next3 = uglyNumbers[p3] * 3;
            int next5 = uglyNumbers[p5] * 5;
            
            int nextUgly = min(next2, min(next3, next5));
            uglyNumbers[i] = nextUgly;

            if (nextUgly == next2) p2++;
            if (nextUgly == next3) p3++;
            if (nextUgly == next5) p5++;
        }
        
        return uglyNumbers[n-1];
    }
};
