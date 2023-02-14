// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// Using Floyed Warshall Algorithm
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &e, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for (auto it : e)
        {
            int u = it[0];
            int d = it[1];
            int w = it[2];

            dist[u][d] = w;
            dist[d][u] = w;
        }

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cntMax = n + 1;
        int node = -1;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                cout << dist[i][j] << " ";
                if (dist[i][j] <= distanceThreshold)
                    cnt++;
            }
            cout << "\n";
            cout << cnt << "\n";
            if (cnt <= cntMax)
            {
                cntMax = cnt;
                node = i;
            }
        }

        return node;
    }
};

// Using Dijkstra (Calculate distance of every node to every other by applying digkstra on every node)

#define pii pair<int, int>

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        vector<pii> adj[n];

        for (auto e : edges)
        {
            int from = e[0];
            int to = e[1];
            int weight = e[2];

            adj[from].push_back({to, weight});
            adj[to].push_back({from, weight});
        }

        for (int i = 0; i < n; i++)
        {
            priority_queue<pii, vector<pii>, greater<pii>> pq;

            // {dist, src}
            pq.push({0, i});
            dist[i][i] = 0;

            while (not pq.empty())
            {
                int weight = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                for (auto it : adj[node])
                {
                    int adjNode = it.first;
                    int adjWeight = it.second;

                    if (dist[i][adjNode] > adjWeight + weight)
                    {
                        dist[i][adjNode] = adjWeight + weight;
                        pq.push({dist[i][adjNode], adjNode});
                    }
                }
            }
        }
        int cntMax = n + 1;
        int node = -1;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= distanceThreshold)
                    cnt++;
            }

            if (cnt <= cntMax)
            {
                cntMax = cnt;
                node = i;
            }
        }

        return node;
    }
};