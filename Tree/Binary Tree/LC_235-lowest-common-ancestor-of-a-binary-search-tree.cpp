/**
 * LeetCode 235 - Lowest Common Ancestor of a Binary Search Tree
 *
 * Topic: Binary Search Tree | Recursion | DFS
 *
 * Approach:
 * Since the tree is a BST:
 *
 * 1. If both p and q are smaller than root,
 *    search in the left subtree.
 *
 * 2. If both p and q are greater than root,
 *    search in the right subtree.
 *
 * 3. Otherwise, p and q lie on different sides
 *    (or root is p/q), so root is the LCA.
 *
 * Time Complexity: O(h)
 * Space Complexity: O(h)
 *
 * h = height of the BST
 */


 
class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        if(root == p || root == q) return root;
           // Both nodes are in the left subtree
        if(p->val < root->val && q->val < root->val)return  lca(root->left , p , q);
           // Both nodes are in the right subtree
        if(p->val > root->val && q->val > root->val)return  lca(root->right , p , q);
          // Nodes are on different sides -> root is LCA
        return root;


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root , p , q);
    }
};