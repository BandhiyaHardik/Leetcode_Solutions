class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, int src, int dest) {
        if(!root)
            return NULL;
        
        if(root->val == src || root->val == dest)
            return root;
        
        TreeNode* l = lowestCommonAncestor(root->left,  src, dest);
        TreeNode* r = lowestCommonAncestor(root->right, src, dest);
        
        if(l && r)
            return root;
        
        return l ? l : r;
    }

    bool findPath(TreeNode* LCA, int target, string& path) {
        if(LCA == NULL) {
            return false;
        }

        if(LCA->val == target) {
            return true;
        }

        path.push_back('L');
        if(findPath(LCA->left, target, path) == true) {
            return true;
        }

        path.pop_back();

        path.push_back('R');
        if(findPath(LCA->right, target, path) == true) {
            return true;
        }

        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root, startValue, destValue);

        string lcaTOSrc  = "";
        string lcaTODest = "";

        findPath(LCA, startValue, lcaTOSrc);
        findPath(LCA, destValue, lcaTODest);

        string result = "";

        for(int i = 0; i < lcaTOSrc.length(); i++) {
            result.push_back('U');
        }

        result += lcaTODest;

        return result;
    }
};
