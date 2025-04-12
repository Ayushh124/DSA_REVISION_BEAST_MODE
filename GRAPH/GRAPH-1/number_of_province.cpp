class Solution {
    public:
        void dfs(unordered_map<int, vector<int>>& adj, int node, vector<bool>& visited) {
            visited[node] = true;  // Mark current node as visited
            for (int& v : adj[node]) {
                if (!visited[v]) {
                    dfs(adj, v, visited);
                }
            }
        }
    
        int findCircleNum(vector<vector<int>>& isCon) {
            int n = isCon.size();
            int cnt = 0;
            vector<bool> visited(n, false);
            unordered_map<int, vector<int>> adj;
    
            // Build adjacency list from isCon matrix
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (isCon[i][j] == 1 && i != j) {
                        adj[i].push_back(j);
                        adj[j].push_back(i);  // Undirected graph
                    }
                }
            }
    
            // Count connected components using DFS
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    cnt++;
                    dfs(adj, i, visited);
                }
            }
    
            return cnt;
        }
    };
    