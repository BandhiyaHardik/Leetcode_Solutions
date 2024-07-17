class Solution {
public:
    
    TreeNode* deleteHelper(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& result) {
        if(root == NULL)
            return NULL;
        
        root->left  = deleteHelper(root->left, st, result);
        root->right = deleteHelper(root->right, st, result);
        
        if(st.find(root->val) != st.end()) {
            if(root->left != NULL)
                result.push_back(root->left);
            
            if(root->right != NULL)
                result.push_back(root->right);
            
            return NULL;
        } else {
            return root;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        
        unordered_set<int> st;
        
        for(int &num : to_delete) {
            st.insert(num);
        }
        
        deleteHelper(root, st, result);
        
        if(st.find(root->val) == st.end()) {
            result.push_back(root);
        }
        
        
        return result;
    }
};