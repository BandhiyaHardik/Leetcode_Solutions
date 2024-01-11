class Solution {
public:
    
    int findMaxDiff(TreeNode* root, int minV, int maxV) {
        if(!root)
            return abs(minV-maxV);
        
        minV = min(root->val, minV);
        maxV = max(root->val, maxV);

        int l = findMaxDiff(root->left,  minV, maxV);
        int r = findMaxDiff(root->right, minV, maxV);


        return max(l, r);

    }

    int maxAncestorDiff(TreeNode* root) {
        int minV = root->val;
        int maxV = root->val;

        return findMaxDiff(root, minV, maxV);
   
    }
};