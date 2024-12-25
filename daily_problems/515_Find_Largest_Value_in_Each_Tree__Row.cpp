class Solution {
public:
    vector<int> result;
    
    void DFS(TreeNode* root, int depth) {
        if(!root)
            return;
        
        if(depth == result.size()) {
            result.push_back(root->val);
        } else {
            result[depth] = max(result[depth], root->val);
        }
        
        DFS(root->left, depth+1);
        DFS(root->right, depth+1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        DFS(root, 0);
        return result;
    }
};