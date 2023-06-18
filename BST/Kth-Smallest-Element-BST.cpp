// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
// TC = SC = O(n)
// Iterative Inorder traversal 

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode* > st;

        TreeNode* curr = root;
        int cnt = 0;

        while(curr or !st.empty()) {
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            cnt++;

            if(cnt == k)
                return curr->val;
            
            curr = curr->right;
        }

        return -1;
    }
};
