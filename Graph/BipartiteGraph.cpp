// https://leetcode.com/problems/is-graph-bipartite/

/*

A graph is Bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

OR

If we are able to color whole graph using only two colors such that no two adjacent nodes in a graph have same color, then graph is called as Bipartite graph.
*/

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Solution using BFS
    bool bfs(vector<vector<int>> &g, vector<int> &colors)
    {
        int rows = g.size(), cols = g[0].size();

        // row, col
        queue<int> q;

        // All connected components
        for (int i = 0; i < rows; i++)
        {
            if (colors[i] == -1)
            {
                q.push(i);
                colors[i] = 0;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    int nodeColor = colors[node];

                    for (auto it : g[node])
                    {
                        if (colors[it] == -1)
                        {
                            colors[it] = nodeColor ^ 1;
                            q.push(it);
                        }
                        else
                        {
                            if (colors[it] == nodeColor)
                                return false;
                        }
                    }
                }
            }
        }

        return true;
    }

    // Solution using DFS
    bool dfs(int node, vector<vector<int>> &g, vector<int> &colors)
    {
        if (colors[node] == -1)
            colors[node] = 0;

        for (auto &it : g[node])
        {
            if (colors[it] == -1)
            {
                colors[it] = colors[node] ^ 1;
                bool ans = dfs(it, g, colors);
                if (!ans)
                    return false;
            }
            else
            {
                if (colors[it] == colors[node])
                    return true;
            }
        }

        return false;
    }

    bool isBipartite(vector<vector<int>> &g)
    {
        int rows = g.size(), cols = g[0].size();

        // -1 => no color
        //  0 => yellow color
        //  1 => red color
        vector<int> colors(rows, -1);

        // bool bfsAnswer = bfs(g, colors);
        // return bfsAnswer;

        bool dfsAnswer;
        for (int i = 0; i < rows; i++)
        {
            if (colors[i] == -1)
            {
                dfsAnswer = dfs(i, g, colors);
                if (dfsAnswer == false)
                    return false;
            }
        }

        return true;
    }
};