/*
    Time Complexity:
        O(N)

    Space Complexity:
        O(H)

    Where:
        N = number of nodes
        H = height of the tree

    Approach:
        DFS + Recursion
        At every node, subtract its value from targetSum.
        At a leaf, check whether the remaining sum is 0.
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
    bool solve(TreeNode* root , int target){
        if(!root) return 0;
        target -=root->val ;
        if(!root->left && !root->right ) return target == 0;
        return solve(root->left , target) || solve(root->right , target);
    }
    bool hasPathSum(TreeNode* root, int target) {
        return solve(root , target);
    }
};
