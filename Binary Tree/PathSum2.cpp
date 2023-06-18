// Path Sum 2
// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

class Solution {
    vector<vector<int>> vans;
public:
    
    void helper(TreeNode* root, int sum, int targetSum, vector<int> v) {
        if(root == NULL)
            return;
        
        sum += root->val;
        v.push_back(root->val);

        if(sum == targetSum and root->left == NULL and root->right == NULL)
        {
            vans.push_back(v);
            return;
        }

        helper(root->left, sum, targetSum, v);
        helper(root->right, sum, targetSum, v);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;

        helper(root, 0, targetSum, v);

        return vans;
    }
};
