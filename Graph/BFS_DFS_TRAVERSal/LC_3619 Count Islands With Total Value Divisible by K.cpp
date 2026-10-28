// TC -> O(m*n) , SC -> O(m*n) for recursion stack

class Solution {
public:
    int m , n ;
    typedef long long ll ;
    ll dfs(int i , int j , vector<vector<int>>&grid){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return 0 ;
        ll sum = 0;
        sum+=grid[i][j];
        grid[i][j] = 0;
        sum += dfs(i + 1, j, grid);
        sum += dfs(i, j + 1, grid);
        sum += dfs(i - 1, j, grid);
        sum += dfs(i, j - 1, grid);

        return sum ;
        
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0 ;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] > 0){
                    ll sum = dfs(i , j , grid);
                    if(sum % k == 0)ans++;
                }
            }
        }
        return ans ;
    }
};