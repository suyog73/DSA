// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCycle(int v, vector<int> adj[])
    {
        vector<bool> visited(v, false);

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                queue<pair<int, int>> q;
                visited[i] = true;

                q.push({i, -1});

                while (!q.empty())
                {
                    int node = q.front().first;
                    int parent = q.front().second;

                    q.pop();

                    for (auto it : adj[node])
                    {

                        if (!visited[it])
                        {
                            visited[it] = true;
                            q.push({it, node});
                        }

                        else if ((parent != it))
                            return true;
                    }
                }
            }
        }
        return false;
    }
};