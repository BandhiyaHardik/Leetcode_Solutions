class Solution {
    using ll = long long;
    int MOD = 1e9+7;
    vector<int> fact,inv_fact;

    int binaryExp(ll a,ll b){
        ll res = 1;
        while(b){
            if(b&1)
                res = (res*a)%MOD;
            a = (a*a)%MOD;
            b /= 2;
        }
        return res;
    }
    int MMI(int val){
        return binaryExp(val,MOD-2);
    }
    void inverseFact(const int& n){
        inv_fact = vector<int>(n+1);
        inv_fact[n] = MMI(fact[n]);
        for(int i=n;i>0;--i)
            inv_fact[i-1] = (1LL*inv_fact[i]*i)%MOD;
    }
    void factorial(const int& n){
        fact = vector<int>(n+1);
        fact[0] = 1;
        for(int i=1;i<=n;++i)
            fact[i] = (1LL*i*fact[i-1])%MOD;
    }
    void precompute(const int& n){
        factorial(n);
        inverseFact(n);
    }
public:
    int countGoodArrays(int n, int m, int k) {
        precompute(n);

        int run_ways = ((1LL * fact[n-1] * inv_fact[n-k-1])%MOD * inv_fact[k])%MOD;
        int ways_to_assign = (1LL * m * binaryExp(m-1,n-k-1))%MOD;
        return (1LL * run_ways * ways_to_assign)%MOD;
    }
};