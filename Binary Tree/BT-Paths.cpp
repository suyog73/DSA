// Binary Tree Paths
// Each recursive call have its own copy of string

class Solution {
    vector<string> vans;
public:
    void preOrder(TreeNode* root, string s) {
        if(root->left == NULL and root->right == NULL) {
            s += to_string(root->val);
            if(s.size())
                vans.push_back(s);
            
            return;
        }
        
        s += to_string(root->val) + "->";
        if(root->left)
            preOrder(root->left, s);

        if(root->right)
            preOrder(root->right, s);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string temp;
        preOrder(root, temp);

        return vans;
    }
};
