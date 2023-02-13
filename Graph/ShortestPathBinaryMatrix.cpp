// https://leetcode.com/problems/shortest-path-in-binary-matrix/

// Solve using Dijkstra to get shortest path 

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, pair<int, int>>

class Solution
{
    int dirX[8] = {1, -1, 0, 0, -1, 1, -1, 1};
    int dirY[8] = {0, 0, 1, -1, -1, -1, 1, 1};

    bool isValid(int i, int j, int n)
    {
        return (i >= 0 and i < n and j >= 0 and j < n);
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &g)
    {
        int n = g.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        dist[0][0] = 0;

        if (g[0][0] == 1 or g[n - 1][n - 1] == 1)
            return -1;

        priority_queue<pii, vector<pii>, greater<pii>> pq;

        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            int nodeDist = pq.top().first;
            int nodeX = pq.top().second.first;
            int nodeY = pq.top().second.second;

            pq.pop();

            for (int i = 0; i < 8; i++)
            {
                int newX = nodeX + dirX[i];
                int newY = nodeY + dirY[i];

                if (isValid(newX, newY, n) and g[newX][newY] == 0 and dist[newX][newY] > nodeDist + 1)
                {
                    dist[newX][newY] = nodeDist + 1;
                    pq.push({dist[newX][newY], {newX, newY}});
                }
            }
        }

        if (dist[n - 1][n - 1] == 1e9)
            return -1;

        return dist[n - 1][n - 1] + 1;
    }
};