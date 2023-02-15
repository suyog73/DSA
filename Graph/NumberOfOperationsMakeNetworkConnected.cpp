// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

// Suyog Patil

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
    int makeConnected(int n, vector<vector<int>> &c)
    {
        DisjointSet ds(n);

        int extraEdges = 0;
        for (auto cc : c)
        {
            int u = cc[0];
            int v = cc[1];

            if (ds.findParent(u) != ds.findParent(v))
                ds.unionBySize(u, v);
            else
                extraEdges++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == ds.findParent(i))
                ans++;
        }

        ans--; // require ans-1 edges to connect all connected components
        if (extraEdges >= ans)
            return ans;

        return -1;
    }
};