// LeetCode 743 - Network Delay Time
// Algorithm: Dijkstra's Algorithm
// TC -> O((V + E) log V)   SC -> O(V + E)

class Solution {
public:
    typedef pair<int , int > P;

    // TC -> O(E log V) , SC -> O(V + E)
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<P>>adj(n);
        for(auto& i: times){
            int u = i[0]-1 , v= i[1]-1 , wt = i[2];
            adj[u].push_back({v , wt});
        }

        priority_queue<P , vector<P> , greater<>>q;
        vector<int>dist(n , INT_MAX);
        dist[k-1] = 0;
        q.push({0 , k-1}); // dist , node

        while(!q.empty()){
            auto [d , node] = q.top();
            q.pop();

            for(auto&[ngbr , wt] : adj[node]){
                if(d + wt < dist[ngbr]){
                    dist[ngbr] = d + wt;
                    q.push({dist[ngbr] , ngbr});
                }
            }
        }

        int ans = *max_element(begin(dist) , end(dist));
        return ans == INT_MAX ? -1 : ans;
    }
};