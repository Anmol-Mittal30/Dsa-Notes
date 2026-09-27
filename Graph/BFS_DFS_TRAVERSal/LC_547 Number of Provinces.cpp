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







// --------------------------------------- using Dsu ------------------------------------------
// TC -> O(n + n² α(n) + n α(n)) , SC-> O(n)

class Dsu{
public:    
    vector<int>prnt;
    vector<int>rank;
    Dsu(int n){
         prnt.resize(n);
         rank.resize(n , 1);
         for(int i = 0 ; i < n ; i++) prnt[i] = i;
    }

    int find(int x){
      if(prnt[x] == x) return x;
      return prnt[x] = find(prnt[x]);

    }
    void Union(int x , int y){
        x = find(x);
        y = find(y);
        if(x == y) return ;
        if(rank[x] < rank[y]) prnt[x] = y;
        else if(rank[x] > rank[y]) prnt[y] = x;
        else rank[x]+=1 , prnt[y] = x;
    }

};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;
        Dsu dsu(n);
        for(int i = 0 ; i < n  ; i++){
            for(int j = i+1; j < n ; j++){
                    if(isConnected[i][j] == 1){
                        dsu.Union(i , j);
                    }
            }
        }

        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(i == dsu.find(i)) ans++;
        }
        return ans ;

    }
};