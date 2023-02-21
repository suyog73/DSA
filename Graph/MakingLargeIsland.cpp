// https://leetcode.com/problems/making-a-large-island/

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
    bool isValid(int i, int j, int n) { return (i >= 0 and j >= 0 and i < n and j < n); }
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();

        DisjointSet ds(n * n);

        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    continue;

                flag = true;

                for (int k = 0; k < 4; k++)
                {
                    int newI = i + dx[k];
                    int newJ = j + dy[k];

                    if (isValid(newI, newJ, n) and grid[newI][newJ])
                    {
                        int currNode = (i * n) + j;
                        int newNode = (newI * n) + newJ;
                        ds.unionBySize(currNode, newNode);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 1;
                if (grid[i][j] == 0)
                {
                    set<int> st;
                    for (int k = 0; k < 4; k++)
                    {
                        int newI = i + dx[k];
                        int newJ = j + dy[k];

                        if (isValid(newI, newJ, n) and grid[newI][newJ])
                        {
                            int currNode = (i * n) + j;
                            int newNode = (newI * n) + newJ;

                            st.insert(ds.findParent(newNode));
                        }
                    }
                    for (auto it : st)
                        sum += ds.size[it];

                    ans = max(ans, sum);
                }
            }
        }

        if (ans == 0) // If matrix is consist of all 1's or 0's
            ans = flag ? n * n : 0;

        return ans;
    }
};