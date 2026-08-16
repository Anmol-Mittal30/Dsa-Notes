```cpp
/*
--------------------------------------------------
Problem    : 90. Subsets II
Topic      : Backtracking / Bit Manipulation
Difficulty : Medium

Approaches :
1. Take / Skip + Duplicate Skipping
2. Backtracking + Sorting + Duplicate Skipping
3. Bitmasking + Set

--------------------------------------------------
*/


class Solution {
public:

    // =========================================================
    // Approach 1 : Take / Skip + Duplicate Skipping
    //
    // Idea:
    // At every index, we have two choices:
    // 1. Take the current element
    // 2. Skip the current element
    //
    // Before taking the skip branch, skip all duplicate
    // elements so that duplicate subsets are not generated.
    //
    // Time  : O(n * 2^n)
    // Space : O(n)          // Excluding output
    // =========================================================

    /*
    int n;
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int i, vector<int>& temp) {

        if (i == n) {
            ans.push_back(temp);
            return;
        }

        // Take nums[i]
        temp.push_back(nums[i]);

        solve(nums, i + 1, temp);

        temp.pop_back();

        // Skip all duplicate elements
        while (i < n - 1 && nums[i] == nums[i + 1])
            i++;

        // Skip nums[i]
        solve(nums, i + 1, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> temp;

        solve(nums, 0, temp);

        return ans;
    }
    */


    // =========================================================
    // Approach 2 : Backtracking + Sorting + Duplicate Skipping
    //
    // Idea:
    // Generate subsets using a loop.
    //
    // The important condition:
    //
    // if (i > idx && nums[i] == nums[i - 1])
    //     continue;
    //
    // This skips duplicate elements at the same recursion level.
    //
    // This is the recommended / optimal approach.
    //
    // Time  : O(n * 2^n)
    // Space : O(n)          // Excluding output
    // =========================================================

    /*
    int n;
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int idx, vector<int>& temp) {

        // Every current subset is a valid answer
        ans.push_back(temp);

        for (int i = idx; i < n; i++) {

            // Skip duplicates at the same recursion level
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);

            solve(nums, i + 1, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> temp;

        solve(nums, 0, temp);

        return ans;
    }
    */


    // =========================================================
    // Approach 3 : Bitmasking + Set
    //
    // Idea:
    // There are 2^n possible subsets.
    //
    // Generate every subset using a bitmask and insert each
    // subset into a set. The set automatically removes
    // duplicate subsets.
    //
    // Time  : O(n^2 * 2^n)
    // Space : O(n * 2^n)    // Including set/output
    // =========================================================

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n = nums.size();

        set<vector<int>> st;

        sort(nums.begin(), nums.end());

        // Generate all 2^n subsets
        for (int mask = 0; mask < (1 << n); mask++) {

            vector<int> temp;

            for (int i = 0; i < n; i++) {

                // Check whether nums[i] is included
                if ((mask >> i) & 1)
                    temp.push_back(nums[i]);
            }

            // Set automatically removes duplicates
            st.insert(temp);
        }

        vector<vector<int>> ans;

        for (auto subset : st)
            ans.push_back(subset);

        return ans;
    }
};
```
