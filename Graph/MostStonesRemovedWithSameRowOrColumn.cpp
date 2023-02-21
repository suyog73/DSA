// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

// Suyog Patil

#include <bits/stdc++.h>
using namespace std;

// ---------------------Disjoint Set---------------------------//

class DisjointSet
{

public:
    vector<int> parent, rank, size;
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
    int removeStones(vector<vector<int>> &stones)
    {
        int maxRow = 0, maxCol = 0;
        for (auto it : stones)
        {
            int x = it[0];
            int y = it[1];

            maxRow = max(maxRow, x);
            maxCol = max(maxCol, y);
        }

        unordered_map<int, int> mp;
        DisjointSet ds(maxRow + maxCol + 1);
        for (auto it : stones)
        {
            int x = it[0];
            int y = it[1] + maxRow + 1;

            mp[x]++;
            mp[y]++;

            ds.unionBySize(x, y);
        }

        int cnt = 0;

        for (auto it : mp)
        {
            int x = it.first;

            if (x == ds.parent[x])
                cnt++;
        }

        return stones.size() - cnt;
    }
};