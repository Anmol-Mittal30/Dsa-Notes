/**
 * LeetCode 236 - Lowest Common Ancestor of a Binary Tree
 *
 * Topic: Binary Tree | Recursion | DFS
 *
 * Approach:
 * Recursively search both left and right subtrees.
 *
 * If current node is:
 * 1. NULL      -> return NULL
 * 2. p or q    -> return current node
 *
 * After searching both sides:
 * - left && right -> current node is the LCA
 * - otherwise     -> return whichever side found p/q
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */



 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // TC -> O(n) , SC-> O(H);
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root == p || root == q) return root;
        TreeNode* left =  lca(root->left , p , q);
        TreeNode* right = lca(root->right , p , q);
        if(left && right) return root;
        return left ? left : right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root , p , q);
    }
};