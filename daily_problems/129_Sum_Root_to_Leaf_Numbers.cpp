class Solution {
public:

    int sumNumbers(TreeNode* root,int sum=0) {

        if(!root){
            return 0;
        }
        sum = sum*10+root->val;

        if(!root->left && !root->right){
            return sum;
        }
        return sumNumbers(root->left,sum)+sumNumbers(root->right,sum);
    }
};