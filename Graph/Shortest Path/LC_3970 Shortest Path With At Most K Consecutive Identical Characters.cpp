class Solution {
public:
    // Time: O((V+E)K * log(VK)) , SC-> O(EK + VK)
    typedef pair<int , int> P;
    typedef tuple<int , int , int> T;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int , vector<P>> adj;
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({v , wt});
        }  

        vector<vector<int>>ans(n , vector<int>(k+1 , INT_MAX));
        ans[0][1] = 0; // means node 0 mein cnt -> 1 dist = 0;

        // min heap -> {dist , node , cnt} cnt of consecutive character
        priority_queue<T , vector<T> , greater<>> pq;
        pq.push({0 , 0 , 1});

        while(!pq.empty()){
            auto [d , node , cnt] = pq.top();
            pq.pop();
            if(d > ans[node][cnt]) continue ;
            if(node == n-1) return d;

            for(auto& [v , wt] : adj[node]){
                int newCnt = (labels[v] == labels[node]) ? cnt+1 : 1 ;
                if(newCnt > k) continue ;
                int newDist = d + wt ;
                if(newDist < ans[v][newCnt]){
                   ans[v][newCnt] =  newDist ;
                   pq.push({newDist , v , newCnt});
                }

            }
        } 
        return -1 ;
    }
};