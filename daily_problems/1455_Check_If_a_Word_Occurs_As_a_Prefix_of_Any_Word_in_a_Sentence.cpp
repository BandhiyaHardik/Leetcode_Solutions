class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1;
        int n = sentence.size();
        int m = searchWord.size();
        int i = 0;

        while (i < n) {
            int j = 0;

            while (i < n && sentence[i] == searchWord[j]) {
                i++;
                j++;
                if (j == m) return index;
            }

            while (i < n && sentence[i] != ' ') i++;
            
            i++;
            index++;
        }

        return -1;
    }
};
