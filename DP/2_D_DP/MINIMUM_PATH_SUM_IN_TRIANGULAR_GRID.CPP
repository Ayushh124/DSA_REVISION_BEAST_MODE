class Solution {
    public:
        int solve(vector<vector<int>>& triangle, int height, int level, int index, vector<vector<int>>& dp) {
            // Base case
            if (level == height) {
                return 0;
            }
           //memo 
            if (dp[level][index] != -1) {
                return dp[level][index];
            }
    
            // Recursive calls for the left and right child
            //left wale search mein hum log bs row change kr rahe hai ,and we are in the same column .
            int left = solve(triangle, height, level + 1, index, dp);
            //in the right serach we are changing the row aas well as the col ...
            int right = solve(triangle, height, level + 1, index + 1, dp);
    
          
            dp[level][index] = triangle[level][index] + min(left, right);
            return dp[level][index];
        }
    
        int minimumTotal(vector<vector<int>>& triangle) {
            int height = triangle.size();
            vector<vector<int>> dp(height, vector<int>(height, -1)); 
            return solve(triangle, height, 0, 0, dp);
        }
    };
    