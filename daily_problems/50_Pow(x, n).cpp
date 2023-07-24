class Solution {
public:
    double myPow(double x, long long int n) {

        double ans=1;
        
        if(n==0 || x==1){
            return 1;
        }
        else if(n<0){
            x=1/x;
            n=-n;
        }
        ans*=x;
        n--;
        int t=0;
        while(n){
            t++;
            if(t<n){
                ans*=ans;
                n-=t;
                t+=t;
            }
            if(n>0){
               ans=ans*x;
                n--;
            }
        }
        return ans;
    }
};