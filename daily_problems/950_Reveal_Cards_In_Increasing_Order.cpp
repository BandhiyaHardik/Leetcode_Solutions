class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        
        queue<int> que;
        vector<int> result(n);
        
        for(int i = 0; i < n; i++) {
            que.push(i);
        }
        
        sort(begin(deck), end(deck));
        
        for(int i = 0; i < n; i++) {
            
            int idx = que.front();
            que.pop();
            
            result[idx] = deck[i];
            
            if(!que.empty()) {
                que.push(que.front());
                que.pop();
            }
            
        }
        
        return result;
    }
};
