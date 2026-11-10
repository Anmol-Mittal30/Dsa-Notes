// class Solution {
// public:
//     int climbStairs(int n, vector<int>& costs) {
//        vector<int>dp(n+1 , 0);
    
//       for(int i = 1; i <=n ; i++){
//                    dp[i] =             costs[i-1] + 1 + dp[i-1];
//         if(i >= 2) dp[i] = min(dp[i] , costs[i-1] + 4 + dp[i-2]);
//         if(i >= 3) dp[i] = min(dp[i] , costs[i-1] + 9 + dp[i-3]);
//         }
      
//       return dp[n];
//     }
// };


// TC -> O(n), SC -> O(1)
class Solution
{
public:
    int climbStairs(int n, vector<int> &costs)
    {
        vector<int> dp(n + 1, 0);
        int a = 0, b = 0, c = 0;
        for (int i = 1; i <= n; i++)
        {
            int curr = costs[i - 1] + min({a + 1, b + 4, c + 9});
            c = b;
            b = a;
            a = curr;
        }

        return a;
    }
};