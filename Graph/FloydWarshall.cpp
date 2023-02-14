// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

// Used to find shortest path from every vertex to every other vertex
// Used to detect negative weight cycle (if distance of any node with itself comes out to be negative then graph contains negative weight cycle).

// Time => O(n^3)

#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &m)
    {
        int n = m.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (m[i][j] == -1)
                    m[i][j] = 1005;

                if (i == j)
                    m[i][j] = 0;
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (m[i][j] == 1005)
                    m[i][j] = -1;
            }
        }
    }
};
