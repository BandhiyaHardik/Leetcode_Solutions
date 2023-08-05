class Solution {
public:

    vector<TreeNode*> solve(int start, int end) {
        
        if(start > end) {
            return {NULL};
        }
        
        if(start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        
        
        vector<TreeNode*> result;
        for(int i = start; i <= end; i++) {
            
            vector<TreeNode*> leftList  = solve(start, i-1);
            vector<TreeNode*> rightList = solve(i+1, end);
            
            for(TreeNode* leftRoot : leftList) {
                
                for(TreeNode* rightRoot : rightList) {
                    
                    TreeNode* root = new TreeNode(i);
                    root->left  = leftRoot;
                    root->right = rightRoot;
                    
                    result.push_back(root);
                    
                }
                
            }
            
        }
        
        return result;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};

