// https://practice.geeksforgeeks.org/problems/topological-sort/1

// BFS solution using queue

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int v, vector<int> adj[])
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

        vector<int> ans;

        while (!q.empty())
        {
            int f = q.front();
            // cout << f <<"\n";
            ans.push_back(f);
            q.pop();

            for (int it : adj[f])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }

        return ans;
    }
};