class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto& pre : prerequisites) {
            int a = pre[0], b = pre[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int nei : adj[node]) {
                inDegree[nei]--;
                if (inDegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return count == numCourses;
    }
};




// class Solution {
// public:
//     bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& vis,
//                   vector<int>& pathVis) {

//         vis[node] = 1;
//         pathVis[node] = 1;

//         for (auto it : adj[node]) {

//             if (vis[it] == 0) {
//                 if (dfsCheck(it, adj, vis, pathVis))
//                     return true;
//             } else if (pathVis[it]) {
//                 return true;
//             }
//         }

//         pathVis[node] = 0;
//         return false;
//     }

//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

//         vector<vector<int>> adj(numCourses);

//         for (auto edge : prerequisites) {
//             int course = edge[0];
//             int prerequisite = edge[1];

//             adj[prerequisite].push_back(course);
//         }

//         vector<int> vis(numCourses, 0);
//         vector<int> pathVis(numCourses, 0);

//         for (int i = 0; i < numCourses; i++) {
//             if (vis[i] == 0) {
//                 if (dfsCheck(i, adj, vis, pathVis))
//                     return false;
//             }
//         }

//         return true;
//     }
// };