// Balanced Binary Tree
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
// TC => O(n)
// SC => O(n) 

class Solution {
public:
    int getHeight(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        
        if(left == -1 or right == -1)
            return -1;

        if(abs(left - right) > 1)
            return -1;       

        return 1 + max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        int ans = getHeight(root);

        return (ans != -1);
    }
};
