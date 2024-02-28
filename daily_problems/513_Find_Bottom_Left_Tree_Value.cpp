class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        
        int bottomLeft;
        que.push(root);
        
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            
            bottomLeft = node->val;
            
            if(node->right) {
                que.push(node->right);
            }
            if(node->left) {
                que.push(node->left);
            }
        }
        
        return bottomLeft;
    }
};  