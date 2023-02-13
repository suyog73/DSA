// https://leetcode.com/problems/cheapest-flights-within-k-stops/

// Apply Dijkstra on stops
// Time complexity => E (as we are not using priority queue(PQ) here)
// We are not PQ here because we are storing the stops in increasing order itself.

#include <vector>
#include <queue>

using namespace std;

#define pii pair<int, pair<int, int>>
class Solution
{

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];

        for (auto f : flights)
        {
            int from = f[0];
            int to = f[1];
            int price = f[2];

            adj[from].push_back({to, price});
        }

        // {stops, {node, price}}
        queue<pii> q;
        vector<int> dist(n, 1e9);

        q.push({0, {src, 0}});
        dist[src] = 0;

        while (not q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();

            if (stops > k)
                break;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int adjPrice = it.second;

                if (dist[adjNode] > price + adjPrice)
                {
                    dist[adjNode] = price + adjPrice;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};