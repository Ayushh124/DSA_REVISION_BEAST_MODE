class Solution {
    public:
        unordered_map<TreeNode*, pair<int, int>> dp;
    
        pair<int, int> robHelper(TreeNode* root) {
            if (!root) return {0, 0};
    
            if (dp.find(root) != dp.end()) return dp[root];
    
            // Recursively solve for left and right children
            pair<int, int> left = robHelper(root->left);
            pair<int, int> right = robHelper(root->right);
    
            // If we rob this node, we cannot rob its immediate children
            int robCurrent = root->val + left.first + right.first;
    
            // If we don't rob this node, we can take max of its children's rob or not-rob values
            int skipCurrent = max(left.first, left.second) + max(right.first, right.second);
    
            return dp[root] = {skipCurrent, robCurrent};
        }
    
        int rob(TreeNode* root) {
            pair<int, int> result = robHelper(root);
            return max(result.first, result.second);
        }
    };
    