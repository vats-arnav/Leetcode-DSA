class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& vis,
                  vector<int>& pathVis, vector<int>& check) {

        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        for (auto it : adj[node]) {

            if (vis[it] == 0) {
                if (dfsCheck(it, adj, vis, pathVis, check)) {
                    check[node] = 0;
                    return true;
                }
            } else if (pathVis[it]) {
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                dfsCheck(i, adj, vis, pathVis, check);
            }
        }
        for (int i = 0; i < V; i++) {
            if (check[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};