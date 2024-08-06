class Solution {
public:
    int minimumPushes(string word) {

        unordered_map<char, int> frequency;
        for (char c : word) {
            frequency[c]++;
        }

        vector<pair<int, char>> freqVec;
        for (auto& pair : frequency) {
            freqVec.push_back({pair.second, pair.first});
        }
        sort(freqVec.rbegin(), freqVec.rend());

        int totalPushes = 0;
        int pushCount = 1;
        int keyIndex = 0;
        
        for (auto& pair : freqVec) {
            int freq = pair.first;
            totalPushes += freq * pushCount;
            keyIndex++;
            if (keyIndex % 8 == 0) {
                pushCount++;
            }
        }

        return totalPushes;
    }
};