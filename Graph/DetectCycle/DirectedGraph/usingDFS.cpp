// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int node, vector<bool> &visited, vector<bool> &dfsVisited, vector<int> adj[])
    {
        visited[node] = true;
        dfsVisited[node] = true;

        for (auto it : adj[node])
        {
            if (visited[it] == false)
            {
                visited[it] == true;
                if (dfs(it, visited, dfsVisited, adj))
                    return true;
            }
            else
            {
                if (dfsVisited[it])
                    return true;
            }
        }

        dfsVisited[node] = false;
        return false;
    }

    bool isCyclic(int v, vector<int> adj[])
    {
        vector<bool> visited(v, false);
        vector<bool> dfsVisited(v, false);

        for (int i = 0; i < v; i++)
        {
            if (visited[i] == false)
                if (dfs(i, visited, dfsVisited, adj))
                    return true;
        }
        return false;
    }
};