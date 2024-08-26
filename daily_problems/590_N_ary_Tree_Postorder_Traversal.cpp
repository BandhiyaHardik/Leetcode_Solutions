class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }
    
private:
    void postorderTraversal(Node* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        for (Node* child : node->children) {
            postorderTraversal(child, result);
        }

        result.push_back(node->val);
    }
};