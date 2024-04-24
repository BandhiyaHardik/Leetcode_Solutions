class Solution {
public:
    int t[38];
    int find(const int& n) {
        if(n == 0)           return 0;
        if(n == 1 || n == 2) return 1;
        if(t[n] != -1)       return t[n];
        
        int a = find(n-1);
        int b = find(n-2);
        int c = find(n-3);
            
        
        return t[n] = a+b+c;
    }
    int tribonacci(int n) {
        memset(t, -1, sizeof(t));
        
        return find(n);
    }
};
