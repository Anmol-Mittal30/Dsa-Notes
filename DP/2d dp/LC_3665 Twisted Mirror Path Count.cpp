class Solution {
public:
    //  TC -> O(m*n*2) , SC-> O(m*n)
    // dp[i][j] = {-1 , -1} 0th , 1st idx
    int Left = 0; // arrive at left side means(it was coming from right dirtn)
    int Up = 1;   // arrive at up side means(it was coming from down dirtn)
    const int mod = 1e9 + 7;
    int m , n;
    vector<vector<array<int , 2>>>dp;
  
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m , vector<array<int, 2>>(n , array<int, 2>{0, 0}));
        dp[0][0][Left] = 1;
        dp[0][0][Up]   = 1;
        // 1st row fill
        for(int j = 1; j < n  ; j++){
            dp[0][j][Left] = 1;
            if(grid[0][j] == 1) break ;
        }
        // 1st col fill
          for(int i = 1; i < m  ; i++){
            dp[i][0][Up] = 1;
            if(grid[i][0] == 1) break ;
        }

        for(int i = 1 ; i < m ; i++){
            for(int j = 1; j < n ; j++){
                //Left
                if(grid[i][j-1] == 1){
                    dp[i][j][Left] = dp[i][j-1][Up];
                } else { // 0 hai
                    dp[i][j][Left] = (dp[i][j-1][Left] + dp[i][j-1][Up]) % mod;
                }
                // Up
                if(grid[i-1][j] == 1){
                    dp[i][j][Up] = dp[i-1][j][Left];
                } else {
                    dp[i][j][Up] = (dp[i-1][j][Left] + dp[i-1][j][Up]) % mod;
                }
            }
        }
        return( dp[m-1][n-1][Left] + dp[m-1][n-1][Up] ) % mod;
    }
};