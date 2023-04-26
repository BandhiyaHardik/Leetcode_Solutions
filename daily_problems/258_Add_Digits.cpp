class Solution {
public:
    int addDigits(int num) {
        while(num>9){
            int ans=0;
            while(num){
                ans=ans+(num%10);
                num/=10;
            }
            num=ans;
        }
        return num;
    }
};
