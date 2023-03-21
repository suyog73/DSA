#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
    {
        vector<int> indegree(n + 1, 0);
        vector<int> adj[n + 1];
        for (int i = 0; i < edges.size(); i++)
        {
            indegree[edges[i][1]]++;

            adj[edges[i][0]].push_back(edges[i][1]);
        }

        queue<int> q;
        vector<int> ans(n, 0);

        for (int i = 1; i < n + 1; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);

                ans[i - 1] = 1;
            }
        }

        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                int node = q.front();
                q.pop();

                for (int it : adj[node])
                {
                    indegree[it]--;

                    if (indegree[it] == 0)
                    {
                        q.push(it);
                        ans[it - 1] = ans[node - 1] + 1;
                    }
                }
            }
        }

        return ans;
    }
};