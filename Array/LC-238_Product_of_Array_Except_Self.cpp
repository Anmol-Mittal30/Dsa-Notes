/*
    Problem: 238. Product of Array Except Self
    Topic: Array, Prefix Product, Suffix Product
    Difficulty: Medium

    Approach 1:
    - Build separate prefix and suffix product arrays.
    - Answer for each index = prefix[i] * suffix[i + 1].

    Time Complexity: O(n)
    Space Complexity: O(n)

    ------------------------------------------------

    Approach 2 (Optimized):
    - Store prefix products directly in the answer array.
    - Traverse from right to left while maintaining a running suffix product.
    - Multiply the current answer with the suffix product.

    Time Complexity: O(n)
    Space Complexity: O(1)   // Excluding the output array
*/

class Solution {
public:
    // Approach 1: Prefix + Suffix Arrays
    vector<int> productExceptSelf1(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n + 1, 1), suf(n + 1, 1);

        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] * nums[i - 1];

        for (int i = n - 1; i >= 0; i--)
            suf[i] = suf[i + 1] * nums[i];

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
            ans[i] = pre[i] * suf[i + 1];

        return ans;
    }

    // Approach 2: Optimized (O(1) Extra Space)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        // Store prefix products
        ans[0] = 1;
        for (int i = 1; i < n; i++)
            ans[i] = ans[i - 1] * nums[i - 1];

        // Multiply with suffix products
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return ans;
    }
};