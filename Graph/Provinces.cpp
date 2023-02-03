// https://leetcode.com/problems/number-of-provinces/


// Time Complexity:- O(V) + O(V + 2E)
// Count number of connected components

#include <vector>
using namespace std;

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