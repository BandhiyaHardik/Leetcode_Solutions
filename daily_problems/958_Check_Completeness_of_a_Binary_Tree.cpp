class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        if(!root) 
            return true;
        queue<TreeNode*> Q;
        Q.push(root);
        bool f = 0;
        while(!Q.empty()){
            auto front = Q.front();
            Q.pop();
            if(front->left){
                if(f)
                 return false;
                Q.push(front->left);
            }
            else
                f=1;
            if(front->right){
                if(f) 
                    return false;
                Q.push(front->right);
            }
            else
                f=1;
        }
        return true;
    }
};