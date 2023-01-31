// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// kKruskal Algorithm

#include <bits/stdc++.h>
using namespace std;

int parent[1005];
int rankSize[1005];

class Solution
{

private:
    // here "n" is a parameter
    void make(int n)
    {
        // set parent of node to node itself
        parent[n] = n;

        // initialize rank of node to 0
        rankSize[n] = 0;
    }

    // It is used to merge two graphs with one parent (chota(rank) to motha graph)
    void unionSet(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);

        if (rankSize[u] < rankSize[v])
            parent[u] = v;

        else if (rankSize[u] > rankSize[v])
            parent[v] = u;

        if (rankSize[u] == rankSize[v])
        {
            parent[u] = v;
            rankSize[v]++;
        }
    }

    int findParent(int node)
    {
        // if node and parent are equal then it is a parent
        if (node == parent[node])
            return node;

        // make recursive call with parent[node]
        return parent[node] = findParent(parent[node]);
    }

public:
    int spanningTree(int n, vector<vector<int>> adj[])
    {

        // {weight, {u, v}}
        vector<pair<int, pair<int, int>>> vp;

        for (int i = 0; i < n; i++)
        {
            // here "i" is a argument
            make(i);
            for (auto it : adj[i])
            {
                vp.push_back({it[1], {i, it[0]}});
            }
        }

        // sort edges according to weights
        sort(vp.begin(), vp.end());

        // for (auto it : vp)
        //     cout << it.first << " " << it.second.first << " " << it.second.second << "\n";

        // min weight of spanning tree
        int ans = 0;
        for (auto it : vp)
        {
            int weight = it.first;
            int u = findParent(it.second.first);
            int v = findParent(it.second.second);

            // If both the nodes of current edge is not belonging to same edge then make their union and add this weight
            if (u != v)
            {
                ans += weight;
                unionSet(u, v);
            }
        }

        return ans;
    }
};