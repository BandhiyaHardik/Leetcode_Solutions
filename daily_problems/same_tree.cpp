class Solution {
    bool areEqual(TreeNode* p, TreeNode* q){
        if(!p && !q) 
          return true;
        if(!p || !q) 
          return false;
        if(p->val != q->val) 
          return false;
        return true;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!areEqual(p, q)) 
             return false;
        queue<TreeNode*> Q1, Q2;
        Q1.push(p);
        Q2.push(q);
        while(!Q1.empty()){
            TreeNode* n1 = Q1.front(); 
            Q1.pop();
            TreeNode* n2 = Q2.front();
            Q2.pop();
            
            if(!areEqual(n1, n2)) 
                 return false;
            if(n1){
                if(!areEqual(n1->left, n2->left)) 
                     return false;
                if(n1->left){
                    Q1.push(n1->left);
                    Q2.push(n2->left);
                }
                if(!areEqual(n1->right, n2->right)) 
                    return false;
                if(n1->right){
                    Q1.push(n1->right);
                    Q2.push(n2->right);
                }
            }
        }
        return true; 
    }
};