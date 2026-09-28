class Solution {
public:
     // Recursion : TC -> O(3^n), SC -> O(n)
    // int n;
    // int solve(int i , vector<int>&nums){
    //     if(i >= n) return 0;
    //     int result = INT_MIN;
    //     result  = max(result,  nums[i] - solve(i+1 , nums)); // only first one take
    //     if(i+1 < n) result = max(result , nums[i] + nums[i+1] - solve(i+2 , nums)); // first 2 
    //     if(i+2 < n) result = max(result , nums[i] + nums[i+1] + nums[i+2] - solve(i+3 , nums)); // first 3
    //     return result ;
    // }
    // string stoneGameIII(vector<int>& nums) {
    //     n= nums.size();
    //     int diff = solve(0 , nums);  // it cal the diff of (alice - bob) score
    //     if(diff > 0) return "Alice";
    //     if(diff < 0) return "Bob";
    //     return "Tie";
    // }

    // Memoisation : TC, SC -> O(n)  
    // int n;
    // vector<int>dp;
    // int solve(int i , vector<int>&nums){
    //     if(i >= n) return 0;
    //     if(dp[i]!= -1) return dp[i];
    //     int result = INT_MIN;
    //     result  = max(result,  nums[i] - solve(i+1 , nums)); // only first one take
    //     if(i+1 < n) result = max(result , nums[i] + nums[i+1] - solve(i+2 , nums)); // first 2 
    //     if(i+2 < n) result = max(result , nums[i] + nums[i+1] + nums[i+2] - solve(i+3 , nums)); // first 3
    //     return dp[i] =  result ;
    // }
    // string stoneGameIII(vector<int>& nums) {
    //     n= nums.size();
    //     dp.assign(n+1 , -1);
    //     int diff = solve(0 , nums);  // it cal the diff of (alice - bob) score
    //     if(diff > 0) return "Alice";
    //     if(diff < 0) return "Bob";
    //     return "Tie";
    // }
    
    // Bottom Up Appraoch   : TC -> O(n) , Sc-> O(n);
    // string stoneGameIII(vector<int>& nums) {
    //     int n= nums.size();
    //     vector<int>dp(n+3 , 0);
    //     for(int i=n-1;i>=0;i--){
    //         int result = nums[i] - dp[i+1];
    //         if(i+1 < n) result = max(result , nums[i] + nums[i+1] - dp[i+2]);
    //         if(i+2 < n) result = max(result, nums[i] + nums[i+1] + nums[i+2] - dp[i+3]);
    //         dp[i] = result ;
            
    //     }

    //     if(dp[0] > 0) return "Alice";
    //     if(dp[0] < 0) return "Bob";
    //     return "Tie";
        
    // }
    
    // Bottom Up Appraoch Space Optimisation  : TC -> O(n) , Sc-> O(1);
    string stoneGameIII(vector<int>& nums) {
        int n= nums.size();
        int a=0; // dp[i+1]; 
        int b=0; // dp[i+2];
        int c=0; // dp[i+3];
        for(int i=n-1;i>=0;i--){
            int result = nums[i] - a ;
            if(i+1 < n) result = max(result , nums[i] + nums[i+1] -b);
            if(i+2 < n) result = max(result, nums[i] + nums[i+1] + nums[i+2] -c);
            c = b;
            b = a;
            a = result ;
            
        }
        
        int diff = a ;
        if(diff > 0) return "Alice";
        if(diff < 0) return "Bob";
        return "Tie";
        
    }
    
};