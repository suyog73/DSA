// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // final weights of edges in MST
        vector<int> dist(v, INT_MAX);

        // storing parent of node (no need of parent just to print)
        vector<int> parent(v, -1);

        // will store all nodes which are required for MST
        vector<int> mst(v, false);

        // pick up any node and initialize its distance with 0
        dist[0] = 0;

        // We will loop from all the vertices and check from which node we will get MST
        for (int i = 0; i < v; i++)
        {
            // min distance
            int mn = INT_MAX;

            // node having least edge weight
            int u = 0;

            // to get u
            for (int j = 0; j < v; j++)
            {
                if (mst[j] == false and dist[j] < mn)
                {
                    mn = dist[j];
                    u = j;
                }
            }

            // take it into mst as it have least weight
            mst[u] = true;

            for (auto it : adj[u])
            {
                int itNode = it[0];
                int w = it[1];

                // If node is not already taken into MST and we have smaller dist then update it
                if (mst[itNode] == false and w < dist[itNode])
                    dist[itNode] = w;
            }
        }
        int ans = 0;

        // get sum of all weights in MST
        for (int d : dist)
        {
            // cout << d << "\n";
            ans += d;
        }

        return ans;
    }
};

// Using Priority Queue

#define pii pair<int, int>
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<bool> visited(n, false);

        // weight, node
        pq.push({0, 0});

        int sum = 0;

        while (!pq.empty())
        {
            int weight = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if (visited[node])
                continue;

            sum += weight;
            visited[node] = true;

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int adjWeight = it[1];

                if (!visited[adjNode])
                    pq.push({adjWeight, adjNode});
            }
        }

        return sum;
    }
};