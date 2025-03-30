class Solution {
    public:
        int solve(int i, vector<int>& dp, vector<int>& nums) {
            if (i < 0) return 0;
            if (dp[i] != -1) return dp[i];
            
            int one = solve(i - 1, dp, nums);
            int two;  
            if (i > 1) {  
                two = nums[i] + solve(i - 2, dp, nums);  
            } else {  
                two = nums[i];  
            }
            
            return dp[i] = max(one, two);
        }
        
        int rob(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n, -1);
            return solve(n - 1, dp, nums);
        }
    };
    