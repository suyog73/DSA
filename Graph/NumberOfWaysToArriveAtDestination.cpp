// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

// Dijkstra (E*log(V))

#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

#define pii pair<long, long>
const int MOD = 1e9 + 7;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pii> adj[n];
        for (auto r : roads)
        {
            long long u = r[0];
            long long v = r[1];
            long long time = r[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // {dist, node}
        priority_queue<pii, vector<pii>, greater<pii>>
            pq;
        pq.push({0, 0});

        vector<long long> dist(n, LONG_MAX);
        dist[0] = 0;

        // Number of path till ith node having same shortest distance
        vector<long long> paths(n, 0);
        paths[0] = 1;

        while (not pq.empty())
        {
            long long nodeDist = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                long long adjNode = it.first;
                long long adjDist = it.second;

                if (dist[adjNode] == adjDist + nodeDist)
                    paths[adjNode] = (paths[adjNode] + paths[node]) % MOD;
                else if (dist[adjNode] > adjDist + nodeDist)
                {
                    dist[adjNode] = adjDist + nodeDist;
                    pq.push({dist[adjNode], adjNode});

                    paths[adjNode] = paths[node];
                }
            }
        }

        return paths[n - 1];
    }
};