// LeetCode 62 - Unique Paths
// Category: Dynamic Programming - Grid DP
// TC: O(m * n), SC: O(m * n) -> 2D DP
// TC: O(m * n), SC: O(n)       -> Space Optimized DP

class Solution {
public:
    int uniquePaths(int m, int n) {

        // Approach 1: 2D DP
        // dp[i][j] = paths from top + paths from left

        /*
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
        */


        // Approach 2: Space Optimized 1D DP
        // dp[j]     = top
        // dp[j - 1] = left

        vector<int> dp(n, 1);

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++)
                dp[j] += dp[j-1];
        }

        return dp[n-1];
    }
};