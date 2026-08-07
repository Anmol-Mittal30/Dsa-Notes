/*
    LeetCode 216 - Combination Sum III

    Topic:
    - Backtracking
    - Recursion
    - Combinatorics

    ---------------------------------------------------------
    Method 1: Take / Skip Backtracking

    Time Complexity : O(2^9 × k)
    Space Complexity: O(k)

    ---------------------------------------------------------
    Method 2: Combination Generation (Preferred)

    Time Complexity : O(C(9, k) × k)
    Space Complexity: O(k)

    Idea:
    Generate combinations in increasing order using a 'start'
    index. Each number is used at most once, eliminating the
    need for a visited array or bitmask.
*/




class Solution {
public:
    vector<vector<int>>ans;
    // Method 1  Tc -> O(2^9⋅k) , Sc-> O(k)​
    // void solve(int k , int n , vector<int>&temp , int sum , int i){
    //         if(sum==n && temp.size()==k){
    //             ans.push_back(temp);
    //             return ;
    //         }
    //         if(i > 9 || temp.size() > k || sum > n) return ;
    //         // skip num ;
    //         solve(k , n , temp , sum , i+1);
    //         // take it 
    //         temp.push_back(i);
    //         solve(k , n , temp , sum+i , i+1);
    //         temp.pop_back();

    // }
    // Method 2  TC -> O(C(9, k) × k)
    void solve(int start , int k , int n , vector<int>&temp){
         if(k==0 && n==0){
            ans.push_back(temp);
            return ;
         }
         for(int i = start; i<=9; i++){
            if(i > n) break ;
            temp.push_back(i);
            solve(i+1 , k-1 , n-i , temp);
            temp.pop_back();
         }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(1 , k , n , temp);
        return ans;
    }
};