// Path Sum
// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

class Solution {
public:

    bool helper(TreeNode* root, int targetSum) {
        if(root == NULL)    
            return false;

        targetSum -= root->val;

        if(targetSum == 0 and root->left == NULL and root->right == NULL)
            return true;

        bool left = helper(root->left, targetSum);
        bool right = helper(root->right, targetSum);

        return left or right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum);
    }
};
