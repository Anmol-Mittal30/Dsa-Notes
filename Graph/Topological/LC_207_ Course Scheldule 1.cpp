// LeetCode 207 - Course Schedule
// Topic: Graph, Topological Sort, BFS, Kahn's Algorithm
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
public:
    // TC = SC ->  O(V + E)
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>indeg(n , 0);
        for(auto& i : pre){
            int v = i[0] , u = i[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int>q;
        int cnt = 0;
        for(int i = 0; i< n;i++){
            if(indeg[i] == 0) q.push(i) , cnt++;
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto j : adj[node]){
                indeg[j]--;
                if(indeg[j] == 0){
                    q.push(j);
                    cnt++;
                }
            }
        }
        return cnt == n ;
    }
};