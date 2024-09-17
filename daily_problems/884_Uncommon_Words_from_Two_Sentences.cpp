class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        vector<string> result;
        
        auto countWords = [&](string sentence) {
            stringstream ss(sentence);
            string word;
            while (ss >> word) {
                wordCount[word]++;
            }
        };

        countWords(s1);
        countWords(s2);

        for (const auto& entry : wordCount) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};
