class Solution {
public:
     // TC -> O(n) , SC-> O(n)
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n <= 1) return nums[n-1];
    //     vector<int>dp(n);
    //     dp[0] = nums[0];
    //     dp[1] = max(nums[0] , nums[1]);
    //     for(int i = 2; i < n ; i++){
    //         dp[i] = max(dp[i-1] , nums[i] + dp[i-2]);
    //     }
    //     return max(dp[n-1] , dp[n-2]);
    // }


    // Approach 2 constant space
    // TC -> O(n) , SC-> O(1)
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums[n-1];
        int a = nums[0];
        int b = max(nums[0] , nums[1]);
        for(int i = 2; i < n ; i++){
            int c  = max(b , nums[i] + a);
            a = b;
            b = c;
        }
        return b ;
    }
};

