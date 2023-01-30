// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void dfs(int node, vector<pair<int, int>> adj[], vector<bool> &visited, stack<int> &st)
    {
        visited[node] = true;

        for (auto it : adj[node])
            if (visited[it.first] == false)
                dfs(it.first, adj, visited, st);

        st.push(node);
    }

    vector<int> shortestPath(int n, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[n];

        for (vector<int> e : edges)
        {
            int source = e[0];
            int dest = e[1];
            int dist = e[2];

            adj[source].push_back({dest, dist});
        }

        // Topological sort
        stack<int> topo;
        vector<bool> visited(n, false);
        dfs(0, adj, visited, topo);

        // Create a distance array

        vector<int> dist(n, INT_MAX);

        int src = 0;
        dist[src] = 0;

        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();

            for (auto it : adj[top])
            {
                if (top != INT_MAX)
                {
                    int node = it.first;
                    int nDist = it.second;

                    dist[node] = min(dist[node], dist[top] + nDist);
                }
            }
        }

        for (int i = 0; i < n; i++)
            if (dist[i] == INT_MAX)
                dist[i] = -1;

        return dist;
    }
};