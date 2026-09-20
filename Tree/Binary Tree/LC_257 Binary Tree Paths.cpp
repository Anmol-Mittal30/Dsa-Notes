
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

// TC → O(N × H) , SC-> O(H)
 class Solution {
public:
    vector<string>ans;  
    void solve(TreeNode* root , string temp){
         if(!root) return ;
         temp += to_string(root->val);
         if(!root->left && !root->right) {
            ans.push_back(temp);
            return ;
         }
         temp+="->";
         solve(root->left , temp);
         solve(root->right , temp);
         
    }
    vector<string> binaryTreePaths(TreeNode* root) {
         string temp = "";
        solve(root , temp);
        return ans ;
    }
};