class Solution {
    public:
        int solve(int i, vector<int>& nums, vector<int>& dp, int start) {
            if (i < start) return 0;
            if (dp[i] != -1) return dp[i];
            
            int robHouse = nums[i] + solve(i - 2, nums, dp, start);
            int skipHouse = solve(i - 1, nums, dp, start);
            
            return dp[i] = max(robHouse, skipHouse);
        }
        
        int rob(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return nums[0];
            //2 dp
                   // 1- bcoz overwrite na ho 
                   // 2-for second call no indecxces contains -1 inn the array bcoz it is itertated before 
    
            vector<int> dp1(n, -1);
            vector<int> dp2(n, -1);
            
            int case1 = solve(n - 2, nums, dp1, 0);  // Exclude last house
            int case2 = solve(n - 1, nums, dp2, 1);  // Exclude first house
            
            return max(case1, case2);
        }
    };
    