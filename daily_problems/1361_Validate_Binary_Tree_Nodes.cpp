class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, vector<int>> parent_to_children;
        unordered_map<int, int> child_to_parent;

        for(int i = 0; i<n; i++) {

            int node   = i;
            int leftC  = leftChild[i];
            int rightC = rightChild[i];

            if(leftC != -1) {
                parent_to_children[node].push_back(leftC);

                if(child_to_parent.find(leftC) != child_to_parent.end()) {
                    return false;
                } else {
                    child_to_parent[leftC] = node;
                }
            }

            if(rightC != -1) {
                parent_to_children[node].push_back(rightC);

                if(child_to_parent.find(rightC) != child_to_parent.end()) {
                    return false;
                } else {
                    child_to_parent[rightC] = node;
                }
            }

        }

        int root = -1;
        
        for(int i = 0; i<n; i++) {
            if(child_to_parent.find(i) == child_to_parent.end()) {
                if(root != -1)
                    return false;
                else
                    root = i;
            }
        }
        if(root == -1)
            return false;

        vector<bool> visited(n, false);
        queue<int> que;
        int count = 1;
        que.push(root);
        visited[root] = true;
        
        while(!que.empty()) { 
            int node = que.front();
            que.pop();

            for(int &child : parent_to_children[node]) {
                if(!visited[child]) {
                    visited[child] = true;
                    count++;
                    que.push(child);
                }
            }

        }

        return count == n; 

    }
};
