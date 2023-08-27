class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int t[2001][2001];
    
    bool solve(vector<int>& stones, int curr_stone_index, int prevJump) {
        if(curr_stone_index == n-1)
            return true;
        
        bool result = false;
        
        if(t[curr_stone_index][prevJump] != -1)
            return t[curr_stone_index][prevJump];
        
        for(int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++) {
            
            if(nextJump > 0) {
                int next_stone = stones[curr_stone_index] + nextJump;
                
                if(mp.find(next_stone) != mp.end()) {
                    result = result || solve(stones, mp[next_stone], nextJump);
                }
            }
            
        }
        
        return t[curr_stone_index][prevJump] = result;
        
    }
    
    bool canCross(vector<int>& stones) {
        
        if(stones[1] != 1)
            return false;
        
        n = stones.size();
        for(int i = 0; i<n; i++) {
            mp[stones[i]] = i;
        }
        
        memset(t, -1, sizeof(t));
        
        return solve(stones, 0, 0);
    }
};