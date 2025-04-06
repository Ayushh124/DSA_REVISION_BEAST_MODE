class Solution {
    public:
        bool find(vector<int>nums,int target,int n, vector<vector<int>>& dp){
            if(target==0){
                return true;
    
            }
            if( n==0||target<0){
                return false;
            }
            if(dp[n][target]!=-1){
                return dp[n][target];
            }
           dp[n][target] =  find(nums,target-nums[n-1],n-1,dp) || find(nums,target,n-1,dp);
           return dp[n][target];
    
    
      }
        bool canPartition(vector<int>& nums) {
            int sum=0;
            int n=nums.size();
    
            for(int i=0;i<n;i++){
                sum=sum+nums[i];
    
    
            }
            
            
    
            if(sum %2 !=0){
                return false;
            }
        
    
                int target=sum/2;
                 vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
                return find(nums,target,n,dp);
    
            
            
            
          
            
        }
    };