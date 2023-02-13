#include <vector>
#include <queue>

using namespace std;

const int MOD = 1e5;
class Solution
{
public:
    int minimumMultiplications(vector<int> &v, int start, int end)
    {
        queue<pair<int, int>> pq;
        vector<int> dist(1e5, 1e9); // storing steps required to get the number

        // {number, steps}
        pq.push({start, 0});
        dist[start] = 0;

        while (not pq.empty())
        {
            int number = pq.front().first;
            int steps = pq.front().second;
            pq.pop();

            for (int vv : v)
            {
                int x = (number * vv) % MOD;

                if (steps + 1 < dist[x])
                {
                    if (x == end)
                        return steps;

                    dist[x] = steps + 1;
                    pq.push({x, steps + 1});
                }
            }
        }

        return -1;
    }
};