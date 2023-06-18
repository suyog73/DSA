// Path Sum 3
// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

class Solution {
    int cnt = 0;
public:
    void getPathSum(TreeNode* root, long long int targetSum) {
        if(root == NULL)
            return;
        
        targetSum -= root->val;

        if(targetSum == 0)
            cnt++;
        
        getPathSum(root->left, targetSum);
        getPathSum(root->right, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {

        if(root == NULL)
            return 0;

        pathSum(root->left, targetSum);
        getPathSum(root, targetSum);
        pathSum(root->right, targetSum);
        
        return cnt;
    }
};
