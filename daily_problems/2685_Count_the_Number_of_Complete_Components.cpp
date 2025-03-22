class Solution {
public:
    class DSU {
        public:
            vector<int> parent;
            vector<int> size;
            DSU(int n) {
                parent.resize(n);
                size.resize(n);
                for(int i = 0; i < n; i++) {
                    parent[i] = i;
                    size[i] = 1;
                }
            }

            int find(int x) {
                if(parent[x] == x) {
                    return x;
                }

                return parent[x] = find(parent[x]);
            }

            void Union(int x, int y) {
                int x_par = find(x);
                int y_par = find(y);

                if(x_par == y_par) {
                    return;
                }

                if(size[x_par] > size[y_par]) {
                    parent[y_par] = x_par;
                    size[x_par] += size[y_par];
                } else if(size[x_par] < size[y_par]) {
                    parent[x_par] = y_par;
                    size[y_par] += size[x_par];
                } else {
                    parent[x_par] = y_par;
                    size[y_par] += size[x_par];
                }
            }
    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_map<int, int> mp;

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            dsu.Union(u, v);
        }

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int root = dsu.find(u);
            mp[root]++;
        }

        int result = 0;
        for(int i = 0; i < n; i++) {
            if(dsu.find(i) == i) {
                int v = dsu.size[i];
                int e = mp[i];

                if((v*(v-1))/2 == e) {
                    result++;
                }
            }
        }

        return result;
    }
};
