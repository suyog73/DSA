// Max height or depth
// TC => O(n)
// SC => O(height) => Recursion Stack

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);        

        return 1 + max(left, right);
    }
};
