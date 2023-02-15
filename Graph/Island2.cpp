// https://practice.geeksforgeeks.org/problems/number-of-islands/1

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
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool isValid(int i, int j, int rows, int cols)
    {
        return (i >= 0 and i < rows and j >= 0 and j < cols);
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        int visited[n][m];
        DisjointSet ds(n * m);
        memset(visited, false, sizeof(visited));

        vector<int> ans;

        int cnt = 0;
        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];

            if (visited[row][col])
            {
                ans.push_back(cnt);
                continue;
            }

            visited[row][col] = true;
            cnt++;

            for (int i = 0; i < 4; i++)
            {
                int newR = row + dx[i];
                int newC = col + dy[i];

                if (isValid(newR, newC, n, m) and visited[newR][newC])
                {
                    int currNode = (row * m) + col;
                    int newNode = (newR * m) + newC;

                    if (ds.findParent(currNode) != ds.findParent(newNode))
                    {
                        cnt--;
                        ds.unionBySize(currNode, newNode);
                    }
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};
