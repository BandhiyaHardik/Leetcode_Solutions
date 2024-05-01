class Solution {
public:
    string reversePrefix(string word, char ch) {
        reverse(begin(word), word.begin()+word.find(ch)+1);
        return word;
        
    }
};