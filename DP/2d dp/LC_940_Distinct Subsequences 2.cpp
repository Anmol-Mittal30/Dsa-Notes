// Recursion  + memo

// class Solution {
// public:
//     const int mod = 1e9 + 7;
//     vector<int>prev ; // when we saw the last character seen (1 based indexing )
//     vector<int>dp;
//     int solve(int n){
//         if(n == 0) return 1;
//         if(dp[n] != -1) return dp[n];
//         int total = (2*solve(n-1)) % mod  ;
//         total %= mod;
//         if(prev[n] != 0){
//         int duplicate = solve(prev[n] - 1) % mod ;
//         total = (total - duplicate + mod) % mod;
//         }
//         return dp[n] = total ;
//     }
//     int distinctSubseqII(string s) {
//         int n = s.size();
//         prev.assign(n+1 , 0);
//         dp.assign(n+1 , -1);
//         vector<int>lastSeen(26 , 0);
//         for(int i = 1; i <= n ; i++){
//             int idx = s[i-1] - 'a';
//             prev[i] = lastSeen[idx];
//             lastSeen[idx] = i ;
//         }

//         return (solve(n) - 1 + mod) % mod ; // why -1 to remoce empty subsequence
//     }
// };


// Bottom Up 
class Solution {
public:
    const int mod = 1e9 + 7 ;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int>prev(n+1 , 0);
        vector<int>dp(n+1 , -1);
        vector<int>lastSeen(26 , 0);
        for(int i = 1; i <= n ; i++){
            int idx = s[i-1] - 'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i ;
        }

        dp[0] = 1;   // if n== 0 then 1
        for(int i = 1; i <= n ; i++){
            int total = (2 * dp[i-1]) % mod ;
            if(prev[i] != 0){
                int duplicates = dp[prev[i] - 1] % mod;
                total = (total - duplicates + mod) % mod;
            }
            dp[i] = total ;
        }
        return (dp[n] - 1 + mod) % mod ;

    }
};