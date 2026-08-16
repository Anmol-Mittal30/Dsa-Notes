/*
### LC-200 — Number of Islands

**Approaches:**
- DFS — Recursive flood fill
- BFS — Queue-based flood fill

**Time Complexity:** O(m × n)

**Space Complexity:**
- DFS: O(m × n) worst case recursion stack
- BFS: O(m × n) worst case queue

**Key Idea:**
Treat every unvisited land cell as the start of an island.
Traverse all connected land cells using DFS/BFS and mark them as
`'0'` so they are not visited again.
*/



class Solution {
public:
    int m, n;
    vector<int> dir = {0, -1, 0, 1, 0};

    // Approach 1: DFS
    // Time: O(m * n)
    // Space: O(m * n) worst case due to recursion stack
    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        for (int k = 0; k < 4; k++) {
            dfs(i + dir[k], j + dir[k + 1], grid);
        }
    }

    // Approach 2: BFS
    // Time: O(m * n)
    // Space: O(m * n) worst case due to queue
    void bfs(int i, int j, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;

        q.push({i, j});
        grid[i][j] = '0';

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ni = i + dir[k];
                int nj = j + dir[k + 1];

                if (ni < 0 || nj < 0 || ni >= m || nj >= n ||
                    grid[ni][nj] == '0')
                    continue;

                grid[ni][nj] = '0';
                q.push({ni, nj});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {
                    bfs(i, j, grid);
                    // dfs(i, j, grid);

                    ans++;
                }
            }
        }

        return ans;
    }
};