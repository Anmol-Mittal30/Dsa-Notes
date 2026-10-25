class Solution
{
public:
    int m, n;
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 1)
            return;
        grid[i][j] = 1;
        dfs(i, j - 1, grid);
        dfs(i - 1, j, grid);
        dfs(i + 1, j, grid);
        dfs(i, j + 1, grid);
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        // if first and last row have zero then use dfs
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 0)
                dfs(i, 0, grid);
            if (grid[i][n - 1] == 0)
                dfs(i, n - 1, grid);
        }

        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] == 0)
                dfs(0, j, grid);
            if (grid[m - 1][j] == 0)
                dfs(m - 1, j, grid);
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};