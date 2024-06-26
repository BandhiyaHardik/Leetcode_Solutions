class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& vec) {
        if(!root)
            return;
        
        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);

    }

    TreeNode* construct(int l, int r, vector<int>& vec) {
        if(l > r)
            return NULL;
        
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(vec[mid]);

        root->left  = construct(l, mid-1, vec);
        root->right = construct(mid+1, r, vec);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inOrder(root, vec);
        int l = 0, r = vec.size()-1;

        return construct(l, r, vec);
    }
};