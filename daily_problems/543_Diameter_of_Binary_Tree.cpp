class Solution {
public:
    
    int diameter(TreeNode* root, int& result) {
        if(!root)
            return 0;
        
        int left  = diameter(root->left, result);
        int right = diameter(root->right, result);
        
        result = max(result, left + right);
        
        return max(left, right) + 1; 
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        int result = INT_MIN;
        
        diameter(root, result);
        
        return result;
    }
};