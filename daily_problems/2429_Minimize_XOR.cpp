class Solution {
public:
    bool isSet(int &x, int bit) {
        return x & (1 << bit);
    }

    bool setBit(int &x, int bit) {
        return x |= (1 << bit);
    }

    bool unsetBit(int &x, int bit) {
        return x &= ~(1 << bit);
    }

    int minimizeXor(int num1, int num2) {
        int x = num1;

        int requiredSetBitCount = __builtin_popcount(num2);
        int currSetBitCount = __builtin_popcount(x);

        int bit = 0;
        if(currSetBitCount < requiredSetBitCount) {
            while(currSetBitCount < requiredSetBitCount) {
                if(!isSet(x, bit)) {
                    setBit(x, bit);
                    currSetBitCount++;
                }
                bit++;
            }
        } else if(currSetBitCount > requiredSetBitCount) {
            while(currSetBitCount > requiredSetBitCount) {
                if(isSet(x, bit)) {
                    unsetBit(x, bit);
                    currSetBitCount--;
                }
                bit++;
            }
        }

        return x;
    }
};
