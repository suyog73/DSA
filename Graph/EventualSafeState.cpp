// https://leetcode.com/problems/find-eventual-safe-states/

/*
Two approches

1. Detecting cycle in a graph
    --> Any node who is part of a cycle or any node who leads to a cycle are not safe node.

2. Using topological sort
    --> Reverse a graph and apply topo sort using bfs

*/

#include <vector>
#include <queue>
using namespace std;

class Solution
{

private:
    void bfs(int n, vector<int> adj[], vector<bool> &check)
    {
        vector<int> inDegree(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            for (int it : adj[i])
                inDegree[it]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            check[node] = true;
            for (int it : adj[node])
            {
                inDegree[it]--;

                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
    }

    bool dfs(int node, vector<bool> &visited, vector<bool> &pathVisited, vector<bool> &check, vector<vector<int>> &g)
    {
        visited[node] = true;
        pathVisited[node] = true;

        for (auto it : g[node])
        {
            if (!visited[it])
            {
                bool cycle = dfs(it, visited, pathVisited, check, g);
                if (cycle)
                    return true;
            }
            else
            {
                if (pathVisited[it])
                    return true;
            }
        }

        pathVisited[node] = false;
        check[node] = true;

        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &g)
    {
        vector<int> safeNodes;

        int rows = g.size();
        int cols = g[0].size();

        vector<bool> visited(rows, false);
        vector<bool> pathVisited(rows, false);
        vector<bool> check(rows, false);

        // DFS
        // for (int i = 0; i < rows; i++)
        // {
        //     if (!visited[i])
        //         dfs(i, visited, pathVisited, check, g);
        // }

        // BFS
        vector<int> revGraph[rows];
        for (int i = 0; i < rows; i++)
            for (int it : g[i])
                revGraph[it].push_back(i);

        bfs(rows, revGraph, check);

        for (int i = 0; i < rows; i++)
        {
            if (check[i])
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
};