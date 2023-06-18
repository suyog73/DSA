// Lowest Common Ancestor of a Binary Search Tree
// The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).

// TC => O(log(n))

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) {
            TreeNode* temp = p;
            p = q;
            q = temp;
        }

        if(p->val <= root->val and q->val >= root->val)
            return root;
        
        if(q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        
        if(p->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        
        return NULL;
    }
};
