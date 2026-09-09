

// TC = O(E + Q × (n + E)) , SC = O(n + E)

class Solution {
public:
  bool ispossible(int a, vector<vector<int>>&adj,int b,vector<bool>&visited){
    visited[a]= true;
    if(a==b) return true;
    bool f=0;
    for(auto &j:adj[a]){
        if(!visited[j]){
          if(ispossible(j,adj,b,visited)) return true;
        // f= f||ispossible(j,adj,b,visited);
        }
    }
    return false;
  }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& arr, vector<vector<int>>& query) {
        vector<vector<int>>adj(n);
        // unordered_map<int,vector<int>>adj;
        int k= arr.size();
        for(int i=0;i<k;i++){
            adj[arr[i][0]].push_back(arr[i][1]);
        }
        int size= query.size();
        vector<bool>ans(size,0);
        for(int i=0;i<size;i++){
            int a= query[i][0];
            int b= query[i][1];
            vector<bool>visited(n,0);
             ans[i]=ispossible(a,adj,b,visited);
          }
        return ans;
    }
};