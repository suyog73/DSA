// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

// Calculate Shortest path in Undirected Graph having unit distance from src to all vertices

#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &e, int n, int m, int s)
    {
        vector<int> dist(n, INT_MAX);
        vector<int> adj[n];

        for (int i = 0; i < m; i++)
        {
            int a = e[i][0];
            int b = e[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dist[s] = 0;

        queue<pair<int, int>> q;
        q.push({s, 0});

        while (!q.empty())
        {
            int node = q.front().first;
            int nodeDist = q.front().second;
            q.pop();

            for (int it : adj[node])
            {
                if (nodeDist + 1 < dist[it])
                {
                    dist[it] = nodeDist + 1;
                    q.push({it, dist[it]});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};