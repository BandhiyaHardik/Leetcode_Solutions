class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }
    
private:
    void postorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        
        postorderHelper(node->left, result);
        
        postorderHelper(node->right, result);
        
        result.push_back(node->val);
    }
};