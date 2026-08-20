/*
    LeetCode 41 - First Missing Positive

    Approach:
    1. Replace all non-positive numbers and numbers greater than n with 1.
    2. Use the sign of nums[num - 1] to mark that `num` exists.
    3. The first positive value indicates the missing positive number.

    Example:
    nums = [3, 4, -1, 1]
    After normalization/marking:
    [-3, 4, -1, -1]
    
    Index 1 is positive -> 2 is missing.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool f = false;

        for (auto &i : nums) {
            if (i == 1)
                f = true;

            if (i <= 0 || i > n)
                i = 1;
        }

        if (!f)
            return 1;

        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            int idx = num - 1;

            if (nums[idx] < 0)
                continue;

            nums[idx] *= -1;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                return i + 1;
        }

        return n + 1;
    }
};