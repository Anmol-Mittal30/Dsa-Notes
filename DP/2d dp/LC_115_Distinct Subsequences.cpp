class Solution {
public:
  
    // Recursion TC -> O(2^n) , SC-> O(n)
    //  int n , m ;
    // int solve(string &s , string &t , int i , int j){
    //     if(j == m) return 1;
    //     if(i == n) return 0;
    //     int ans = 0 ;
    //     if(s[i] == t[j]) ans += solve(s , t , i+1 , j+1) + solve(s , t , i+1 , j);
    //     else ans += solve(s , t , i+1 , j);
    //     return ans ;
    // }
    // int numDistinct(string s, string t) {
    //     n = s.size() , m = t.size();
    //     return solve(s , t , 0 , 0);
    // }

   // Recursion + Memo TC -> O(n * m) , SC -> O(n * m)
    // int n , m ;
    // vector<vector<int>>dp;
    // int solve(string &s , string &t , int i , int j){
    //     if(j == m) return 1;
    //     if(i == n) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int ans = 0 ;
    //     if(s[i] == t[j]) ans += solve(s , t , i+1 , j+1) + solve(s , t , i+1 , j);
    //     else ans += solve(s , t , i+1 , j);
    //     return dp[i][j] =  ans ;
    // }
    // int numDistinct(string s, string t) {
    //     n = s.size() , m = t.size();
    //     dp.assign(n+1 , vector<int>(m+1 , -1));
    //     return solve(s , t , 0 , 0);
    // }

    // Bottom Up  TC -> O(n*m) , SC-> O(n*m)
    int numDistinct(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<unsigned long long>> dp( n + 1, vector<unsigned long long>(m + 1, 0));
        // if i = 0 then dp[0][j] = 0  and j = 0 , dp[i][0] = 1 (empty string case)
        for(int i = 0; i <= n  ; i++) dp[i][0] = 1; 
        for(int i = 1; i <=n ; i++){
            for(int j = 1; j <=m ; j++){
              if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
               else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};