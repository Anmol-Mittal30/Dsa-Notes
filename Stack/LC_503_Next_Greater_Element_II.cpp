/*
    LeetCode 503 - Next Greater Element II

    Topic:
    - Stack
    - Monotonic Stack
    - Circular Array

    Approach:
    - Use a monotonic decreasing stack to store indices.
    - Traverse the array twice (0 to 2*n - 1) to simulate a circular array.
    - For every element, pop smaller elements from the stack and update
      their next greater element.
    - Push indices only during the first pass.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < 2 * n; i++) {
            int curr = nums[i % n];

            while (!st.empty() && nums[st.top()] < curr) {
                ans[st.top()] = curr;
                st.pop();
            }

            if (i < n)
                st.push(i);
        }

        return ans;
    }
};