class Solution {
    public:
         int solve(int m,int n,int i,int j,vector<vector<int>>&dp){
            if(i<0 ||i>=m || j<0 || j>=n ){
                return 0;
    
            }
            if(i==m-1&&j==n-1){
                return 1;
    
    
            }
            if(dp[i][j]!=-1){
                return dp[i][j];
    
            }
            int right=solve(m,n,i+1,j,dp);
            int down=solve(m,n,i,j+1,dp);
             dp[i][j]=right+down;
            return dp[i][j];
         }
        int uniquePaths(int m, int n) {
               vector<vector<int>> dp(m, vector<int>(n, -1));
          return solve(m,n,0,0,dp);
        }
    };