/*
LeetCode 102: Binary Tree Level Order Traversal

Approach:
- Use BFS with a queue.
- Store the number of nodes in the current level using q.size().
- Process exactly those nodes and push their children.
- Store each level separately in the answer.

Time Complexity: O(n)
Space Complexity: O(n)


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int>temp;
            while(sz--){
            auto node = q.front();
            q.pop();
            int a = node->val;
            temp.push_back(a);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

           }
           ans.push_back(temp);
        }
        return ans;
    }
};