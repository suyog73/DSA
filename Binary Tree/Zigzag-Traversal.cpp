// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

// TC => O(n)
//  SC => O(n)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);

        if(root == NULL)
            return ans;

        // LeftToRight
        bool ltr = true;

        while(not q.empty()) {
            int size = q.size();

            int idx = 0;
            vector<int> v(size, 0);

            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                idx = i;

                if(!ltr)
                    idx = size-i-1;
                
                v[idx] = node->val;

                if(node->left != NULL)
                    q.push(node->left);
                
                if(node->right != NULL)
                    q.push(node->right);
            }
            ans.push_back(v);
            ltr = !ltr;
        }

        return ans;
    }
};
