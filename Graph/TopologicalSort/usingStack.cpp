// https://practice.geeksforgeeks.org/problems/topological-sort/1

// DFS solution using stack

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    stack<int> st;

public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited)
    {
        visited[node] = true;

        for (auto it : adj[node])
        {
            if (!visited[it])
                dfs(it, adj, visited);
        }
        st.push(node);
    }

    vector<int> topoSort(int v, vector<int> adj[])
    {
        vector<bool> visited(v, false);

        for (int i = 0; i < v; i++)
        {
            if (visited[i] == false)
                dfs(i, adj, visited);
        }
        vector<int> vans;

        while (!st.empty())
        {
            vans.push_back(st.top());
            st.pop();
        }
        return vans;
    }
};