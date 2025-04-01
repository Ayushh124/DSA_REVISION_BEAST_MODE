class Solution {
    public:
        int solve(int m,int n,int i,int j,vector<vector<int>>&dp,vector<vector<int>>& grid){
            if(i==m-1 && j==n-1){
                return dp[i][j]=grid[i][j];
    
            }
            if(dp[i][j]!=-1){
                return dp[i][j];
    
            }
            else if(i==m-1){
                return dp[i][j]=grid[i][j]+solve(m,n,i,j+1,dp,grid);
    
            }
            else if(j==n-1){
                return dp[i][j]=grid[i][j]+solve(m,n,i+1,j,dp,grid);
    
            }
            else {
                return dp[i][j]=grid[i][j]+min(solve(m,n,i,j+1,dp,grid),solve(m,n,i+1,j,dp,grid));
            }
        }
        int minPathSum(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
             vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
            int ans=solve(m,n,0,0,dp,grid);
            return ans;
            
        }
    };