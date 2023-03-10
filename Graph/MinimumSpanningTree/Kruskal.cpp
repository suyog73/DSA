// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// kKruskal Algorithm

#include <bits/stdc++.h>
using namespace std;

// ---------------------Disjoint Set---------------------------//

class DisjointSet
{
    vector<int> parent, rank, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i < n + 1; i++)
            parent[i] = i;
    }

    int findParent(int u)
    {
        if (u == parent[u])
            return u;

        return parent[u] = findParent(parent[u]); // Path compression
    }

    void unionByRank(int u, int v)
    {
        int upU = findParent(u); // ultimate parent of U
        int upV = findParent(v); // ultimate parent of V

        // belonging to same component
        if (upU == upV)
            return;

        if (rank[upU] < rank[upV])
            parent[upU] = upV;

        else if (rank[upU] > rank[upV])
            parent[upV] = upU;

        else
        {
            parent[upV] = upU;
            rank[upU]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int upU = findParent(u); // ultimate parent of U
        int upV = findParent(v); // ultimate parent of V

        // belonging to same component
        if (upU == upV)
            return;

        if (size[upU] < size[upV])
        {
            parent[upU] = upV;
            size[upV] += size[upU];
        }
        else
        {
            parent[upV] = upU;
            size[upU] += size[upV];
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> vp;
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                vp.push_back({it[1], {it[0], i}});
            }
        }

        sort(vp.begin(), vp.end());

        DisjointSet ds(n);
        int mst = 0;
        for (auto it : vp)
        {
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findParent(u) != ds.findParent(v))
            {
                mst += it.first;
                ds.unionBySize(u, v);
            }
        }

        return mst;
    }
};