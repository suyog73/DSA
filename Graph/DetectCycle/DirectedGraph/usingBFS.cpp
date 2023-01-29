// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCyclic(int v, vector<int> adj[])
    {
        vector<int> inDegree(v, 0);

        for (int i = 0; i < v; i++)
        {
            for (int node : adj[i])
                inDegree[node]++;
        }

        queue<int> q;
        for (int i = 0; i < v; i++)
            if (inDegree[i] == 0)
                q.push(i);

        int cnt = 0;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            cnt++;

            for (int it : adj[f])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }

        return (cnt != v);
    }
};