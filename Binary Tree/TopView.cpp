// Top View of Binary Tree

class Solution
{
    public:

    vector<int> topView(Node *root)
    {
        map<int, int> mp;
        queue<pair<Node*,int>>q;
        vector<int> ans;

        if(root == NULL)
            return ans; 
        
        q.push({root, 0});
        
        while(!q.empty()) {
            int sz = q.size();
            
            while(sz--) {
                Node* node = q.front().first;
                int key = q.front().second;
                
                q.pop();
                
                if(mp.find(key) == mp.end()) {
                    mp[key] = node->data;
                }
                
                if(node->left) {
                    q.push({node->left, key - 1});
                }
            
                if(node->right) {
                    q.push({node->right, key + 1});
                }
            }
        }
        
        for(auto it:mp) {
            // cout << it.first << " " << it.second << "\n";
            ans.push_back(it.second);
        }
        
        return ans;
    }

};
