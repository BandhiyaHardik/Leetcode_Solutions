class Solution {
public:
    vector<int> ans;

    void inorder(TreeNode* root){
        
        if(root->left!=NULL){
            inorder(root->left);
        }
        ans.push_back(root->val);
        if(root->right!=NULL){
            inorder(root->right);
        }
        return;
    }

    int minDiffInBST(TreeNode* root) {
       
        inorder(root);
        int k=INT_MAX;
        for(int i=1;i<ans.size();i++){
            k=min(k,(ans[i]-ans[i-1]));
        }
        return k;
      
    }
};