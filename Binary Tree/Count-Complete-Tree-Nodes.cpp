// Count Complete Tree Nodes
// Every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

// TC => O(log(n) * log(n))
// SC => O(n)

class Solution {
public:

    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        TreeNode* rootLeft = root->left;
        TreeNode* rootRight = root->right;

        int left = 1;
        int right = 1;

        while(rootLeft != NULL) {
            left++;
            rootLeft = rootLeft->left;
        }

        while(rootRight != NULL) {
            right++;
            rootRight = rootRight->right;
        }

        if(left == right) {
            return (1 << left) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
