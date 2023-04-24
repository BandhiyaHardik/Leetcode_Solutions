class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> p;
        for(int i=0;i<stones.size();i++){
            p.push(stones[i]);
        }
        while(p.size()>1){
            int ans=p.top();
            p.pop();
            ans=ans-p.top();
            p.pop();
            p.push(ans);
        }
        return p.top();
    }
};