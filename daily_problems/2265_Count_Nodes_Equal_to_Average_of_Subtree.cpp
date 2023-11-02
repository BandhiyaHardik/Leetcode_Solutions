class Solution {
public:
    int result;
    
    int sum(TreeNode* root, int &count) {
        if(!root)
            return 0;
        
        count++;
        
        int l = sum(root->left, count);
        int r = sum(root->right, count);
        
        return l + r + root->val;
    }
    
    void solve(TreeNode* root) {
        if(!root)
            return;
        
        int count = 0;
        int totalSum = sum(root, count);
        
        if((totalSum)/count == root->val) {
            result++;
        }
        
        solve(root->left);
        solve(root->right);
        
    }
    
    int averageOfSubtree(TreeNode* root) {
        result = 0;
        
        solve(root);
        
        return result;
    }
};