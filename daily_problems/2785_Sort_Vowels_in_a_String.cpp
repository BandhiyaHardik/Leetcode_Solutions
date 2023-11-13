class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    string sortVowels(string s) {
        unordered_map<char, int> mp;
        
        for(char &ch : s) {
            if(isVowel(ch)) {
                mp[ch]++;
            }
        }
        
        string temp   = "AEIOUaeiou";
        
        int j = 0; 
        
        for(int i = 0; i<s.length(); i++) {
            
            if(isVowel(s[i])) {
                while(mp[temp[j]] == 0) {
                    j++;
                }
                
                s[i] = temp[j];
                mp[temp[j]]--;
            }
            
        }
        
        return s;
        
    }
};
