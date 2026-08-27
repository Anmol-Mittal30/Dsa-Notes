
/*
LeetCode 994: Rotting Oranges

Approach:
- Use Multi-Source BFS with a queue.
- Push all initially rotten oranges into the queue.
- Process the queue level by level.
- Each level represents 1 minute.
- For every rotten orange, rot its 4 adjacent fresh oranges.
- At the end, if any fresh orange remains, return -1.

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

class Solution {
public:
    int m , n;
    vector<int>dir = {0 , -1 , 0 , 1 , 0};
   
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        queue<pair<int , int>>q;
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j] == 2) q.push({i , j});
            }
        }

        int time = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [i , j] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int ni = i+dir[k];
                    int nj = j+dir[k+1];
                    if(ni < 0 || nj < 0 || ni>=m || nj>=n || grid[ni][nj] !=1) continue;
                      grid[ni][nj] = 2;
                     q.push({ni , nj});
                   }
            }
            time++;
        }

        for(auto i:grid)
        for(auto j:i)
        if(j == 1) return -1;

        return time == 0 ? 0 : time - 1;
        
    }
};