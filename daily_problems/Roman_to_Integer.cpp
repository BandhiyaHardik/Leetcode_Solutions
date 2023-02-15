class Solution {
public:
    int romanToInt(string s) {
        int total =0;
        unordered_map<char, int>mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        for(int i = 0; i < s.size()-1; i++){
            if(mp[s[i]] >= mp[s[i+1]]) 
            total += mp[s[i]];
            else
            total -= mp[s[i]];

        }
        
        total += mp[s.back()];
        return total;
    }
};