class Solution {
public:
    // TC -> O(n) , SC-> O(n)
    int n ;
    void dfs(vector<int>& edges, int node , vector<int>& dist){
        int v = edges[node];
        if(v != -1 && dist[v] == INT_MAX){
            dist[v] = 1 + dist[node];
            dfs(edges , v , dist);
        }
    }
    void bfs(vector<int>& edges, int node , vector<int>& dist){
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int v = edges[node];
            if(v!= -1 && dist[v] == INT_MAX){
                dist[v] = 1 + dist[node];
                q.push(v);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        vector<int>dist1(n , INT_MAX);
        vector<int>dist2(n , INT_MAX);
        dist1[node1] = 0;
        dist2[node2] = 0;
        // using dfs
        // dfs(edges , node1 , dist1);
        // dfs(edges , node2 , dist2);

        // using bfs 
        bfs(edges , node1 , dist1);
        bfs(edges , node2 , dist2);

        int minDist = INT_MAX;
        int minNode = -1;
        for(int i = 0 ; i < n ; i++){
            if (dist1[i] == INT_MAX || dist2[i] == INT_MAX)  continue;
            int maxDist = max(dist1[i] , dist2[i]);
            if(minDist > maxDist){
                minDist = maxDist;
                minNode = i;
            }
        }
        return minNode;
    }
};