// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> ans;

public:
    void dfs(int idx, vector<int> adj[], vector<bool> &visited)
    {
        visited[idx] = true;
        ans.push_back(idx);

        for (auto it : adj[idx])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited);
            }
        }
    }

    vector<int> dfsOfGraph(int v, vector<int> adj[])
    {
        vector<bool> visited(v, false);
        dfs(0, adj, visited);

        return ans;
    }
};