/*
--------------------------------------------------
Problem    : 40. Combination Sum II
Topic      : Backtracking
Difficulty : Medium
Approach   : Backtracking + Sorting + Duplicate Skipping

Time  : O(2^n)
Space : O(n)      // Excluding output

--------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void solve(vector<int>& candidates, int target , vector<int>&temp , int startidx){
        if(target < 0 ) return;
        if(target == 0){
            ans.push_back(temp);
            return ;
        }
        for(int i= startidx ;i<n;i++){
            if(i > startidx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            temp.push_back(candidates[i]);
            solve(candidates , target - candidates[i] , temp , i+1);
            temp.pop_back();
          }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(begin(candidates) , end(candidates));
        vector<int>temp;
        solve(candidates , target , temp , 0);
        return ans;
    }
};