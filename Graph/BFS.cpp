// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfsOfGraph(int v, vector<int> adj[])
    {
        vector<bool> visited(v, false);

        vector<int> ans;
        queue<int> q;
        q.push(0);

        visited[0] = true;

        while (!q.empty())
        {
            int tp = q.front();
            q.pop();

            ans.push_back(tp);

            for (auto it : adj[tp])
            {
                if (!visited[it])
                {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }

        return ans;
    }
};
