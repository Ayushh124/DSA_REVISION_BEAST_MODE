class Solution {
    public:
        int solve(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp, int n) {
            // Base case: If we're at the last row, return the current cell's value
            if (row == n - 1) {
                return matrix[row][col];
            }
    
            // Check if the value is already computed
            if (dp[row][col] != -1) {
                return dp[row][col];
            }
    
            int minisum = INT_MAX;
    
            // Check for all valid paths (down-left, down, down-right)
            if (col - 1 > 0 && row+1<n) {
                minisum = min(minisum, solve(matrix, row + 1, col - 1, dp, n));
            }
            if(row+1<n){
            minisum = min(minisum, solve(matrix, row + 1, col, dp, n));
            }
            if (col + 1 < n && row+1<n) {
                minisum = min(minisum, solve(matrix, row + 1, col + 1, dp, n));
            }
    
            // Add the current cell's value to the minimum sum of the next row
            return dp[row][col] = matrix[row][col] + minisum;
        }
    
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int result = INT_MAX;
    
            // Initialize dp array with -1
            vector<vector<int>> dp(n, vector<int>(n, -1));
    
            // Try starting from each column in the first row
            for (int col = 0; col < n; col++) {
                result = min(result, solve(matrix, 0, col, dp, n));
            }
    
            return result;
        }
    };