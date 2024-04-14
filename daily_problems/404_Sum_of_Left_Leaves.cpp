class Solution {
public:
    int sum(TreeNode* curr, TreeNode* parent) {
        if(!curr)
            return 0;
        
        int left  = sum(curr->left, curr);
        int right = sum(curr->right, curr);
        
        int sum = 0;
        if(curr->left == NULL && curr->right == NULL) {
            if(parent && parent->left == curr)
                sum += curr->val;
        }
        
        return left+right+sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        TreeNode* parent = NULL;
        return sum(root, parent);
    }
};
