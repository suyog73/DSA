// Diameter/Width of Binary Tree
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// TC => O(n) 
// SC => O(n)

class Solution {
public:
    int getHeight(TreeNode* root, int &ans) {
        if(root == NULL)
            return 0;
        
        int left = getHeight(root->left, ans);
        int right = getHeight(root->right, ans);

        ans = max(ans, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        getHeight(root, ans);

        return ans;
    }
};
