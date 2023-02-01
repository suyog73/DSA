// https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int dfs(int node, int &parent, vector<int> &disc, vector<int> &low, vector<bool> &visited, int timer, vector<int> adj[], int &c, int &d)
    {

        bool flag = false;
        visited[node] = true;
        disc[node] = low[node] = timer++;

        for (int it : adj[node])
        {
            // If node itself is a parent then skip it
            if (parent == it)
                continue;

            // if not visited call dfs
            if (!visited[it])
            {
                dfs(it, node, disc, low, visited, timer, adj, c, d);

                // While backtracking update the low of node
                low[node] = min(low[it], low[node]);

                // condition to check for bridge
                if (low[it] > disc[node])
                {
                    if ((it == c and node == d) or (it == d and node == c))
                    {
                        flag = true;
                        break;
                    }
                }
            }
            else
            {
                low[node] = min(low[node], disc[it]);
            }
            if (flag)
                break;
        }
        if (flag)
            return 1;
    }

    int isBridge(int n, vector<int> adj[], int c, int d)
    {
        int timer = 0;
        int parent = -1;

        // It will store what time the ith node get discovered
        vector<int> disc(n, -1);

        // It will store the lowest time of insertion around all its adjacent nodes
        vector<int> low(n, -1);

        // Is node is visited or not
        vector<bool> visited(n, false);

        // check for all node
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
                // Apply dfs and try to find bridge
                if (dfs(i, parent, disc, low, visited, timer, adj, c, d) == 1)
                    return 1;
        }

        return 0;
    }
};