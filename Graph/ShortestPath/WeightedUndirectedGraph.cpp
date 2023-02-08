// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

// Shortes path in weighted undirected graph
// Dijkstra

#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

#define pii pair<int, int>

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pii> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        // {dist, node}
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> parent(n + 1);
        vector<int> dist(n + 1, 1e9);

        dist[1] = 0;
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        pq.push({0, 1});
        while (!pq.empty())
        {
            int nodeDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int weight = it.second;

                if (dist[adjNode] > nodeDist + weight)
                {
                    dist[adjNode] = nodeDist + weight;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        if (dist[n] == 1e9)
            return {-1};

        vector<int> path;
        int node = n;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        return path;
    }
};
