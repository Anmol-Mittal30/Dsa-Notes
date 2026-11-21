// #LeetCode 3331 – Find Subtree Sizes After Changes

// ### Approach: DFS + Last Seen Array

// **Intuition:**

// We need to find the nearest ancestor of each node having the same character as the current node.

// Instead of traversing all ancestors for every node, we maintain a `last` array of size 26.

// - `last[c]` stores the nearest ancestor (or previously visited node on the current DFS path) having character `c`.
// - Initially, all entries are `-1`.
// - During DFS, we store the current node in `last[c]`.
// - Before updating, we save the previous value as `nearAncestr`.
// - After processing all children, we restore the previous value using backtracking.
// - If a matching ancestor exists, we update the current node's parent.
// - Finally, we add the current subtree size to its new parent's answer.

// ### Algorithm

// 1. Build the adjacency list using the original parent array.
// 2. Initialize every subtree size to 1.
// 3. Initialize the `last` array with `-1`.
// 4. Perform DFS starting from root node `0`.
// 5. Track the nearest matching ancestor using the `last` array.
// 6. Restore the previous state during backtracking.
// 7. Update parent relationships and merge subtree sizes.

// ### Complexity Analysis

// - **Time Complexity:** O(n)
//   - Every node is visited exactly once.
//   - Each node performs constant-time operations.

// - **Space Complexity:** O(n)
//   - Adjacency list: O(n)
//   - Answer array: O(n)
//   - DFS recursion stack: O(n)
//   - Last seen array: O(26) = O(1)

// ### Key Concepts

// - Depth First Search (DFS)
// - Tree Traversal
// - Backtracking
// - Parent Reassignment
// - Subtree Size Calculation

// **Tags:** #LeetCode #CPP #DFS #Trees #Backtracking #DSA

// **Time Complexity:** O(n)  
// **Space Complexity:** O(n)



class Solution
{
public:
    //  TC = SC  = O(n)
    int n;
    vector<int>last; // last seen of that char of which node
    vector<int>ans;
    vector<vector<int>>adj;
    void dfs(int currNode , vector<int>& parent, string& s){

        int c = s[currNode] - 'a';
        int nearAncestr = last[c];
        last[c] = currNode ;
        for(int child : adj[currNode]){
            dfs(child , parent , s);
        }
        // now back to at currNode
        last[c] = nearAncestr ;
      
        // if curr is root then no ancstor
        if(currNode != 0){
            int newparent = parent[currNode];
            if(nearAncestr != -1) newparent = nearAncestr;
            parent[currNode] = newparent ;
            ans[newparent] += ans[currNode];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        n = parent.size();
        ans.assign(n , 1);
        last.assign(26 , -1);
        adj.assign(n , {});
        for(int i = 1; i < n ; i++){
            int u = parent[i];
            int v = i;
            adj[u].push_back(v);
        }
        dfs(0 , parent , s); // currNode , prnt , givenStr
        return ans ;
    }
};