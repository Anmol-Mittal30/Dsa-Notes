## 121. Best Time to Buy and Sell Stock

### Category
**DP → 1D DP / State Compression**

### Approach 1: Prefix Minimum
- Store the minimum price up to each index.
- Calculate maximum profit using the previous minimum.

**TC:** O(n)  
**SC:** O(n)

### Approach 2: Space Optimized
- Maintain only the minimum price seen so far.
- Calculate and update maximum profit on the fly.

**TC:** O(n)  
**SC:** O(1)

### Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Approach 1: Prefix Minimum
        // TC -> O(n), SC -> O(n)

        // int n = prices.size();
        // vector<int> pre(n);
        // pre[0] = prices[0];

        // for(int i = 1; i < n; i++)
        //     pre[i] = min(pre[i - 1], prices[i]);

        // int ans = 0;

        // for(int i = 1; i < n; i++)
        //     ans = max(ans, prices[i] - pre[i - 1]);

        // return ans;


        // Approach 2: Space Optimized
        // TC -> O(n), SC -> O(1)

        int n = prices.size();
        int mini = prices[0];
        int ans = 0;

        for(int i = 1; i < n; i++) {
            mini = min(mini, prices[i]);
            ans = max(ans, prices[i] - mini);
        }

        return ans;
    }
};