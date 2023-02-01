// https://practice.geeksforgeeks.org/problems/articulation-point-1/1

/*
Articulation point:- 
    A vertex is said to be an articulation point in a graph if removal of the vertex and associated edges disconnects the graph.
    Inshort, removal of articulation point increases number of connected components. 

1. Apply dfs till their is a connected unvisited node

2. If it and parent are equal then continue

3. While backtracking after finishing dfs calls, update
    --> low[node] = min(low[node], low[it])

4. Check for AP
    Condition for articulation point :- 
        --> low[child] >= disc[parent] and parent != -1
        --> parent == -1 and child of node must be greater than 1

5. If node is already visited then update
    low[node] = min(low[node], disc[it])

*/


#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int node, int &parent, int &timer, vector<int> adj[], vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<bool> &ap)
    {
        visited[node] = true;
        disc[node] = low[node] = timer++;

        int child = 0;

        for (int it : adj[node])
        {
            if (it == parent)
                continue;

            if (visited[it] == false)
            {
                dfs(it, node, timer, adj, disc, low, visited, ap);
                low[node] = min(low[node], low[it]);

                // check for articulation point(AP)
                if (parent != -1 and low[it] >= disc[node])
                    ap[node] = true;

                if (parent == -1)
                    child++;
            }
            else
            {
                low[node] = min(low[node], disc[it]);
            }
        }

        if (child > 1)
            ap[node] = true;
    }

    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        int timer = 0;
        int parent = -1;

        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<bool> visited(n, false);
        vector<bool> ap(n, false);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
                dfs(0, parent, timer, adj, disc, low, visited, ap);
        }

        vector<int> ans;
        for (int i = 0; i < ap.size(); i++)
            if (ap[i])
                ans.push_back(i);

        if (ans.size() == 0)
            ans.push_back(-1);

        return ans;
    }
};