// Lowest Common Ancestor of a Binary Tree
// The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).
// TC => O(n)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root or root == p or root == q)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p ,q);
        TreeNode* right = lowestCommonAncestor(root->right, p ,q);

        if(left == NULL)
            return right;
        
        else if(right == NULL)  
            return left;
        
        return root;
    }
};
