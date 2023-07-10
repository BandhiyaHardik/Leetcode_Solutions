class Solution {
public:
    int minDepth(TreeNode* root) {

        if(root==NULL){
            return 0;
        }

        int leftt=minDepth(root->left);

        int rightt=minDepth(root->right);
        
        if(min(leftt,rightt)!=0){
            return min(leftt,rightt)+1;
        }
        else{
            return max(leftt,rightt)+1;
        }
    }
};