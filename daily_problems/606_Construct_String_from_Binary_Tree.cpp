class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root) {
            return "";
        }
        
        string result = to_string(root->val);
        string l = tree2str(root->left);
        string r = tree2str(root->right);
       
        if(!root->left && !root->right) {
            return result;
        }
        
        if(!root->right)
            return result + "(" + l + ")";
        
        if(!root->left)
            return result + "()" + "(" + r + ")";
        
        return result + "(" + l + ")" + "(" + r + ")";
    }
};