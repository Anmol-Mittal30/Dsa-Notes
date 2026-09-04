// 213. House Robber II
// Topic: Dynamic Programming -> 1D DP
//
// Idea:
// Houses are arranged in a circle, so we cannot rob both
// the first and the last house.
//
// Therefore, divide the problem into two cases:
//
// Case 1: Exclude the last house
//         -> Rob houses from index 0 to n-2
//
// Case 2: Exclude the first house
//         -> Rob houses from index 1 to n-1
//
// Then take the maximum of both cases.

class Solution {
public:

    // =========================================================
    // Approach 1: DP Array
    // TC -> O(n)
    // SC -> O(n)
    // =========================================================

    /*
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n, 0);

        // Case 1: Exclude last house
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n - 1; i++) {
            // Either skip current house
            // or rob current + best from two houses before
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        int case1 = dp[n - 2];

        // Reset dp for Case 2
        dp.assign(n, 0);

        // Case 2: Exclude first house
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);

        for (int i = 3; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        int case2 = dp[n - 1];

        return max(case1, case2);
    }
    */


    // =========================================================
    // Approach 2: Space Optimized DP
    // TC -> O(n)
    // SC -> O(1)
    // =========================================================

    // Solves normal House Robber for a given range [start, end].
    //
    // We only need the previous two DP values:
    //
    // a = dp[i - 2]
    // b = dp[i - 1]
    //
    // current = max(
    //     b,              // skip current house
    //     nums[i] + a     // rob current house
    // )

    int takingHouseRange(vector<int>& nums, int start, int end) {
        int a = 0;
        int b = 0;

        for (int i = start; i <= end; i++) {
            int c = max(b, nums[i] + a);

            a = b;
            b = c;
        }

        return b;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        // Case 1: Exclude last house
        int case1 = takingHouseRange(nums, 0, n - 2);

        // Case 2: Exclude first house
        int case2 = takingHouseRange(nums, 1, n - 1);

        return max(case1, case2);
    }
};