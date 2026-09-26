// TC -> O(n^2) , SC-> O(n^2) for adjacency matrix and O(n) for adjacency list

class Solution {
public:
int n;
void bfs(int vrtx,vector<vector<int>>&adj,vector<bool>&visit){
    queue<int>q;
    q.push(vrtx);
    visit[vrtx]=1;
    while(!q.empty()){
        int node= q.front();
        q.pop();
        for(auto j:adj[node]){
        if(!visit[j]){
            q.push(j);
            visit[j]=1;
        }
    }
    }
}
void dfs(int node,vector<bool>&visit,vector<vector<int>>&arr){
    // visit[node]=1;
    // for(auto j:adj[node]){
    //    if(!visit[j]) dfs(j,visit,adj);    // dfs normal with adj 
     // }
     visit[node]=1;
     for(int j=0;j<n;j++){
        if(!visit[j] && arr[node][j]==1) dfs(j,visit,arr);
     }
    return ;
}
    int findCircleNum(vector<vector<int>>& arr) {
       n= arr.size();
      vector<vector<int>>adj(n);
      for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
       if(arr[i][j]==1) adj[i].push_back(j);
      vector<bool>visit(n,0);
      int cnt=0;
      // using bfs 
      for(int i=0;i<n;i++){
        if(!visit[i]){
            cnt++;
            bfs(i,adj,visit);
        }
      }
      return cnt;
    // using dfs 
//       for(int i=0;i<n;i++){
//         if(!visit[i]){
//             cnt++;
//             // dfs(i,visit,adj);  with adjacency 
//             dfs(i,visit,arr);   // without  passing adjacency matrix 
//         }
//       }
//  return cnt;




  }
};