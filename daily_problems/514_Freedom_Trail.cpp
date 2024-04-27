class Solution {
public:
    int t[101][101];
    
    int countSteps(int ringIndex, int i, int n) {
        int dist       = abs(i - ringIndex);
        int wrapAround =  n - dist;
        
        return min(dist, wrapAround);
    }
    
    int solve(int ringIndex, int keyIndex, string& ring, string& key) {
        
        if (keyIndex == key.length()) {
            return 0;
        }
        
        if(t[ringIndex][keyIndex] != -1) {
            return t[ringIndex][keyIndex];
        }
        
        int result = INT_MAX;
        for (int i = 0; i < ring.length(); i++) {
            if (ring[i] == key[keyIndex]) {
                int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 +
                                            solve(i, keyIndex + 1, ring, key);
                result = min(result, totalSteps);
            }
        }
        
        return t[ringIndex][keyIndex] = result;
    }
    
    int findRotateSteps(string ring, string key) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, ring, key);
    }
};
