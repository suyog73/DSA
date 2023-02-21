// All DFS traversals
// 1 = preorder {root, left, right}
// 2 = inorder {left, root, right}
// 3 = postorder {left, right, root}

#include <vector>
#include <stack>
#include <stddef.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {

        if (root == NULL)
            return {};

        // 1 = preorder
        // 2 = inorder
        // 3 = postorder

        stack<pair<TreeNode *, int>> st;
        // change second parameter to get different traversals
        st.push({root, 1});
        vector<int> preorder, inorder, postorder;
        while (!st.empty())
        {
            TreeNode *top = st.top().first;
            int idx = st.top().second;

            st.pop();
            if (idx == 1)
            {
                preorder.push_back(top->val);
                idx++;
                st.push({top, idx});

                if (top->left != NULL)
                    st.push({top->left, 1});
            }
            else if (idx == 2)
            {
                inorder.push_back(top->val);
                idx++;
                st.push({top, idx});

                if (top->right != NULL)
                    st.push({top->right, 1});
            }
            else
                postorder.push_back(top->val);
        }
        return inorder;
    }
};