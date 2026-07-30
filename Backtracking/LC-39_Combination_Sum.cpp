/*
--------------------------------------------------
Problem    : 39. Combination Sum
Topic      : Backtracking
Difficulty : Medium
Approach   : Backtracking with Start Index

Time  : O(n^(target / minCandidate))   // Worst case
Space : O(target / minCandidate)       // Excluding output

--------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(vector<int>& candidates, int target,
               vector<int>& temp, int startidx) {

        if (target < 0) return;

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = startidx; i < n; i++) {

            if (candidates[i] > target)
                break;

            temp.push_back(candidates[i]);

            solve(candidates,
                  target - candidates[i],
                  temp,
                  i);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        n = candidates.size();

        sort(candidates.begin(), candidates.end());

        vector<int> temp;

        solve(candidates, target, temp, 0);

        return ans;
    }
};