class Solution {
public:
      // Recursion + Memo 
    // int n ;
    // vector<int>t;
    // int solve(int i , vector<int>&pre){
    //     if(i == n-1){
    //         return pre[i];
    //     }
    //     if(t[i] != -1) return t[i];
    //     int take = pre[i] - solve(i+1 , pre);
    //     int skip = solve(i+1 , pre);
    //     return t[i] =  max(take , skip);
    // }
    // int stoneGameVIII(vector<int>& stones) {
    //     n = stones.size();
    //     vector<int>pre(n+1 , 0);
    //     t.assign(n , -1);
    //     pre[0] = stones[0];
    //     for(int i = 1; i<n; i++) pre[i] = pre[i-1] + stones[i];
    //     // why we take i = 1-> bcoz we have to take min 2 stones
    //     return solve(1 , pre);  // Alice - Bob

    // }

    // Bottom Up TC -> O(n) , Sc-> O(n)
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int>pre(n , 0);
        pre[0] = stones[0];
        for(int i = 1; i < n; i++) pre[i] = pre[i-1] + stones[i];

        vector<int>dp(n , INT_MIN);
        dp[n-1] = pre[n-1];
        for(int i = n-2; i >= 1 ; i--) {
            int take = pre[i] - dp[i+1];
            int skip = dp[i+1];
            dp[i] = max(take , skip);
        }
        return dp[1];   // why 1 bcoz we need atleast 2 stones pick at a time

    }
};