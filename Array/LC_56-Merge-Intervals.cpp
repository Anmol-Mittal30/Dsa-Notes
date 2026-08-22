/*
    LeetCode 56 - Merge Intervals

    Category: Arrays
    Pattern: Intervals + Sorting + Greedy

    Approach:
    1. Sort intervals by starting time.
    2. Store the first interval in the answer.
    3. For every next interval:
       - If its start <= last interval's end,
         merge them by updating the end.
       - Otherwise, add it as a new interval.

    Time Complexity: O(n log n)
        - Sorting: O(n log n)
        - Traversal: O(n)

    Space Complexity: O(n)
        - Answer array: O(n)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(begin(intervals), end(intervals));

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            int x = intervals[i][0];
            int y = ans.back()[1];

            if (x <= y)
                ans.back()[1] = max(intervals[i][1], y);
            else
                ans.push_back(intervals[i]);
        }

        return ans;
    }
};