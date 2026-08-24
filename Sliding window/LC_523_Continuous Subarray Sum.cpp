/*
    LeetCode 523 - Continuous Subarray Sum

    Approach:
    - Store the first index where each prefix-sum remainder occurs.
    - If the same remainder appears again, the sum of elements
      between those two indices is divisible by k.
    - We need at least 2 elements, so check index difference >= 2.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int curr = 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            curr = (curr + nums[i]) % k;

            if (mp.count(curr)) {
                if (i - mp[curr] >= 2)
                    return true;
            }
            else {
                mp[curr] = i;
            }
        }

        return false;
    }
};