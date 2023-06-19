// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 
// 1. Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
// 2. Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary
// 3. Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.

class Solution {
public:
    void traverseLeft(Node* root, vector<int> &ans) {
        if(root == NULL)
            return;
            
        if(root->left == NULL and root->right == NULL)
            return;
        
        ans.push_back(root->data);
        
        if(root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }
    
    void traverseLeaf(Node* root, vector<int> &ans) {
        if(root == NULL)
            return;
            
        if(root->left == NULL and root->right == NULL)
            ans.push_back(root->data);
        
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
    void traverseRight(Node* root, vector<int> &ans) {
        if(root == NULL)
            return;

        if(root->left == NULL and root->right == NULL)
            return;
            
        if(root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);
            
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        
        // Left
        traverseLeft(root->left, ans);
        
        // Left side Leaf
        traverseLeaf(root->left, ans);
        
        // Right side Lead
        traverseLeaf(root->right, ans);
        
        // Right
        traverseRight(root->right, ans);
        
        return ans;
    }
};
