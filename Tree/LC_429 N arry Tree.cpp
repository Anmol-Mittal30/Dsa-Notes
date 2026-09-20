/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>>ans;
    // TC -> O(n) , SC-> O(n);
    // void dfs(Node* node , int level){
    //     if(!node) return ;
    //     if(ans.size() == level) ans.push_back({});
    //     ans[level].push_back(node->val);
    //     for(auto child : node->children){
    //         dfs(child , level + 1);
    //     }

    // }

    void bfs(Node* root){
        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            vector<int>temp;
            int sz = q.size();
            while(sz--){
                auto node = q.front();
                q.pop() ; 
                temp.push_back(node->val);
                for(auto child : node->children){
                    if(child) q.push(child);
                }
            }
            ans.push_back(temp);
        }
        
    }
    vector<vector<int>> levelOrder(Node* root) {
       if(!root) return ans ;
    //    dfs(root , 0);
          bfs(root);
       return ans ;
      

    }
};