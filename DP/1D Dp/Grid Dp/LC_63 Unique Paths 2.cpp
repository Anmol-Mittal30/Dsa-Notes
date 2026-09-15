class Solution {
public:
    // recursion
    // int m , n;
    // int solve(int i , int j , vector<vector<int>>& og){
    //     if(i >= m || j >= n) return 0;
    //     if(og[i][j]==1) return 0;
    //     if(i==m-1 && j==n-1) return 1;
    //     return solve(i , j+1 , og) + solve(i+1 , j , og);
    // }
    // int uniquePathsWithObstacles(vector<vector<int>>& og) {
    //     m= og.size();
    //     n= og[0].size();
    //     return solve(0 , 0 , og);
    // }

    //  Memoisation
    // int m , n;
    // vector<vector<int>>dp;
    // int solve(int i , int j , vector<vector<int>>& og){
    //     if(i >= m || j >= n) return 0;
    //     if(og[i][j]==1) return 0;
    //     if(i==m-1 && j==n-1) return 1;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     return  dp[i][j] =  solve(i , j+1 , og) + solve(i+1 , j , og);
    // }
    // int uniquePathsWithObstacles(vector<vector<int>>& og) {
    //     m= og.size();
    //     n= og[0].size();
    //     dp.assign(m , vector<int>(n , -1));
    //     return solve(0 , 0 , og);
    // }

    //  //  Bottom Up Approach 
    // int m , n;
    // int uniquePathsWithObstacles(vector<vector<int>>& og) {
    //     m= og.size();
    //     n= og[0].size();
    //    vector<vector<int>>dp(m , vector<int>(n , -1));
    //     if(og[0][0]==1) return 0;
    //     dp[0][0] = 1;
    //     for(int i=1;i<m;i++) dp[i][0] = og[i][0]==1? 0 : dp[i-1][0]; 
    //     for(int j=1;j<n;j++) dp[0][j] = og[0][j]==1? 0 : dp[0][j-1];

    //     for(int i=1;i<m;i++){
    //         for(int j=1;j<n;j++){
    //             if(og[i][j]==1) dp[i][j] = 0;
    //             else dp[i][j] = dp[i-1][j] + dp[i][j-1];

    //         }
    //     }
    //     return dp[m-1][n-1];
    // }

    //  Bottom Up Space Optimsing 
    int m , n;
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        m= og.size();
        n= og[0].size();
       vector<int>dp(n , 0);
        if(og[0][0]==1) return 0;
        dp[0] = 1;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(og[i][j]==1) dp[j] = 0;
                else if(j > 0) dp[j]= dp[j] + dp[j-1];   // down + right 

            }
        }
        return dp[n-1];
    }
};