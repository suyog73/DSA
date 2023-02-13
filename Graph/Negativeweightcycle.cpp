// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1

#include <vector>
using namespace std;

class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        vector<int> dist(n, 1e9);
        for (int i = 0; i < n - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int d = it[2];

                if (dist[v] > dist[u] + d)
                    dist[v] = dist[u] + d;
            }
        }

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int d = it[2];

            if (dist[v] > dist[u] + d)
                return true;
        }

        return false;
    }
};