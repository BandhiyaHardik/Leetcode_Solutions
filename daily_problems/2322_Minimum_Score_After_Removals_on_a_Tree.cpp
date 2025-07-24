class Solution {
public:
    vector<vector<int>> tree;
    vector<int> xorVal, parent;

    void dfs(int node, int par, vector<int>& nums) {
        xorVal[node] = nums[node];
        parent[node] = par;
        for (int nei : tree[node]) {
            if (nei == par) continue;
            dfs(nei, node, nums);
            xorVal[node] ^= xorVal[nei];
        }
    }

    bool isAncestor(int u, int v) {
        while (v != -1) {
            if (u == v) return true;
            v = parent[v];
        }
        return false;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.assign(n, {});
        xorVal.assign(n, 0);
        parent.assign(n, -1);

        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        dfs(0, -1, nums);
        int totalXor = xorVal[0];
        int minScore = INT_MAX;

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = i, b = j;
                if (isAncestor(a, b)) {
                    int x = xorVal[b];
                    int y = xorVal[a] ^ xorVal[b];
                    int z = totalXor ^ xorVal[a];
                    minScore = min(minScore, max({x, y, z}) - min({x, y, z}));
                } else if (isAncestor(b, a)) {
                    int x = xorVal[a];
                    int y = xorVal[b] ^ xorVal[a];
                    int z = totalXor ^ xorVal[b];
                    minScore = min(minScore, max({x, y, z}) - min({x, y, z}));
                } else {
                    int x = xorVal[a];
                    int y = xorVal[b];
                    int z = totalXor ^ xorVal[a] ^ xorVal[b];
                    minScore = min(minScore, max({x, y, z}) - min({x, y, z}));
                }
            }
        }

        return minScore;
    }
};