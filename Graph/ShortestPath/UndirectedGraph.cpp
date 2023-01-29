// https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    vector<int> adj[n];

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    queue<int> q;
    s--, t--;
    q.push(s);

    visited[s] = true;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (int it : adj[f])
        {
            if (visited[it] == false)
            {
                parent[it] = f;
                visited[it] = true;

                q.push(it);
            }
        }
    }

    vector<int> ans;

    ans.push_back(t + 1);

    while (t != s)
    {
        t = parent[t];
        ans.push_back(t + 1);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
