class Solution
{
public:
    // using the mark down approach  by O(1) approach
    void setZeroes(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        bool firstrow = 0, firstcol = 0;
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 0)
            {
                firstcol = 1;
                break;
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] == 0)
            {
                firstrow = 1;
                break;
            }
        }

        // make their first row and col to makezero to remember that
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    grid[i][0] = 0; // make that row zero
                    grid[0][j] = 0; // make that col  zero
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (grid[i][0] == 0 || grid[0][j] == 0)
                    grid[i][j] = 0;
            }
        }

        if (firstrow)
        {
            for (int j = 0; j < n; j++)
                grid[0][j] = 0;
        }
        if (firstcol)
        {
            for (int i = 0; i < m; i++)
                grid[i][0] = 0;
        }
    }
};