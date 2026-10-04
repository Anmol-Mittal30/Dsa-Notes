class Solution {
public:
    // TC -> O(n) , SC -> O (n)
     bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root) ;
        bool pastNull = false ;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node == NULL) {
                pastNull = true ;
                continue ;
            }
            if(pastNull == true ) return false ;
            q.push(node->left);
            q.push(node->right);
        }
        return true ;
    }
};