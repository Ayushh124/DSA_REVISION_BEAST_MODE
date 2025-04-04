class Solution {
    public:
        int solveusingmem(vector<vector<int>>& obs, int i, int j, vector<vector<int>>& dp) {
            int m = obs.size();
            int n = obs[0].size();
    
            if (i < 0 || i >= m || j < 0 || j >= n || obs[i][j] == 1) {
                return 0; // Out of bounds or obstacle
            }
            if (i == m - 1 && j == n - 1) {
                return 1; // Reached the destination
            }
            if (dp[i][j] != -1) {
                return dp[i][j]; // Use memoized result
            }
    
            int right = solveusingmem(obs, i, j + 1, dp);
            int down = solveusingmem(obs, i + 1, j, dp);
            dp[i][j] = right + down; // Memoize the result
            return dp[i][j];
        }
    
        int uniquePathsWithObstacles(vector<vector<int>>& obs) {
            int m = obs.size();
            int n = obs[0].size();
    
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return solveusingmem(obs, 0, 0, dp); // Start from the top-left corner
        }
    };