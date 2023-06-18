// Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.
// TC => O(n)
// SC => O(n)

class Solution
{
    bool ans = true;
public:

    int heightSum(Node* root) {
        if(root == NULL)
            return 0;
        
        if(root->left == NULL and root->right == NULL)
            return root->data;
            
        int left = heightSum(root->left);
        int right = heightSum(root->right);
            
        if(root->data != left + right)
            ans = false;
        
        return root->data + left + right;
    }
    
    bool isSumTree(Node* root)
    {
        heightSum(root);
        
        return ans;
    }
};
