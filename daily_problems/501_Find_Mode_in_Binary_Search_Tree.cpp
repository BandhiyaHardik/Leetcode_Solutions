class Solution {
public:
    unordered_map<int, int> mp;
    
    void dfs(TreeNode* root) {
        if(!root)
            return;
        
        dfs(root->left);
        mp[root->val]++;
        dfs(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        
        vector<int> result;
        int maxFreq = 0;
        
        for(auto &it : mp) {
            if(it.second > maxFreq) {
                maxFreq = it.second;
                result = {};
                result.push_back(it.first);
            } else if (it.second == maxFreq) {
                result.push_back(it.first);
            }
        }
        
        return result;
        
    }
};