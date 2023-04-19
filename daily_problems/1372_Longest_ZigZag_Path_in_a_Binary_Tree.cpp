class Solution {
public:

    void solve(TreeNode* root,int steps,bool goleft,int &ans)
    {
        if(!root)return;
        ans=max(ans,steps);
        if(goleft)
        {
            if(root->left)
            {
                solve(root->left,steps+1,false,ans);
            }
            if(root->right)
            {
                solve(root->right,1,true,ans);
            }
            
        }
        else{
            if(root->left)
            {
                solve(root->left,1,false,ans);
            }
            if(root->right)
            {
                solve(root->right,steps+1,true,ans);
            }
        }
    }
    int longestZigZag(TreeNode* root) {
        int ans=0;
        solve(root,0,true,ans);
        return ans;
    }
};