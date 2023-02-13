// https://leetcode.com/problems/path-with-minimum-effort/

// Use Digkstra to find minimum cost

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, pair<int, int>>

class Solution
{
    int dirX[4] = {1, 0, -1, 0};
    int dirY[4] = {0, 1, 0, -1};

    bool isValid(int i, int j, int rows, int cols)
    {
        return (i >= 0 and i < rows and j >= 0 and j < cols);
    }

public:
    int minimumEffortPath(vector<vector<int>> &h)
    {
        int rows = h.size();
        int cols = h[0].size();

        // dist , {x, y}
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> dist(rows, vector<int>(cols, 1e9));

        dist[0][0] = 0;

        while (not pq.empty())
        {
            int nodeDist = pq.top().first;
            int nodeX = pq.top().second.first;
            int nodeY = pq.top().second.second;

            pq.pop();

            if (dist[nodeX][nodeY] < nodeDist)
                continue;

            if (nodeX == rows - 1 and nodeY == cols - 1)
                return nodeDist;

            for (int i = 0; i < 4; i++)
            {
                int newX = nodeX + dirX[i];
                int newY = nodeY + dirY[i];

                if (isValid(newX, newY, rows, cols))
                {
                    int addDist = max(nodeDist, abs(h[newX][newY] - h[nodeX][nodeY]));

                    if (addDist < dist[newX][newY])
                    {
                        dist[newX][newY] = addDist;
                        pq.push({addDist, {newX, newY}});
                    }
                }
            }
        }

        return 0;
    }
};
