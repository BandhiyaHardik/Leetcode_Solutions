class Solution {
public:
    int bestClosingTime(string customers) {

        int n=customers.size();

        int penalty=0;

        for(int i=0;i<n;i++)
        {
            if(customers[i]=='N') 
                penalty++;
        }
        
        int ans=n;
        int mini=penalty;
        for(int i=n-1;i>=0;i--)
        {
            if(customers[i]=='Y') 
                penalty++;
            else    
                penalty--;
            if(penalty<=mini){
                mini=penalty;
                ans=i;
            }
        }
        return ans;
    }
};