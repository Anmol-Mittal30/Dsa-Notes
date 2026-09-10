// LeetCode 322 - Coin Change
// Approach 1: Recursion + Memoization (Top-Down DP)
// Time Complexity: O(amount * number_of_coins)
// Space Complexity: O(amount)

class Solution {
public:
    int t[10001];

    int solve(int amount, vector<int>& coins) {
        // Base Case: Amount becomes 0
        // No more coins are needed.
        if (amount == 0)
            return 0;

        // Invalid case: Amount becomes negative
        if (amount < 0)
            return 1e9;

        // Already calculated
        if (t[amount] != -1)
            return t[amount];

        int ans = 1e9;

        // Try taking every coin
        for (auto coin : coins) {
            ans = min(ans, 1 + solve(amount - coin, coins));
        }

        return t[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(t, -1, sizeof(t));

        int ans = solve(amount, coins);

        // No valid combination exists
        return ans >= 1e9 ? -1 : ans;
    }
};



// 
// LeetCode 322 - Coin Change
// Approach 2: Bottom-Up DP
// Time Complexity: O(amount * number_of_coins)
// Space Complexity: O(amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // dp[i] = minimum number of coins required to make amount i
        vector<int> dp(amount + 1, 1e9);

        // 0 coins are required to make amount 0
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {

            for (auto coin : coins) {

                // We can use this coin only if coin <= current amount
                if (i - coin >= 0) {

                    // Take 1 coin + answer for remaining amount
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // If amount is still unreachable, return -1
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};