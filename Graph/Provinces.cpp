// https://leetcode.com/problems/number-of-provinces/

// Time Complexity:- O(V) + O(V + 2E)
// Count number of connected components

#include <vector>
using namespace std;

// Using Simple DFS

class Solution
{
public:
    void dfs(int node, vector<bool> &visited, vector<int> adj[])
    {
        visited[node] = true;

        for (auto it : adj[node])
            if (!visited[it])
                dfs(it, visited, adj);
    }

    int findCircleNum(vector<vector<int>> &g)
    {
        int n = g.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] and i != j)
                    adj[i].push_back(j);
            }
        }

        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans++;
                dfs(i, visited, adj);
            }
        }

        return ans;
    }
};

// Using Disjoint Set

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
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        DisjointSet ds(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j])
                    ds.unionBySize(i, j);
            }
        }

        int provinces = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == ds.findParent(i))
                provinces++;
        }

        return provinces;
    }
};