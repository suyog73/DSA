// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int node, int parent, vector<int> adj[], vector<bool> &visited)
    {
        visited[node] = true;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                bool cycle = dfs(it, node, adj, visited);

                if (cycle)
                    return true;
            }
            else
            {
                if (parent != it)
                    return true;
            }
        }
        return false;
    }

    bool isCycle(int v, vector<int> adj[])
    {
        vector<bool> visited(v, 0);

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, -1, adj, visited))
                    return true;
            }
        }
        return false;
    }
};