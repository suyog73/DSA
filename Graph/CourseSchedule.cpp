// https://leetcode.com/problems/course-schedule/
// https://leetcode.com/problems/course-schedule-ii/

// Question can be done using topological sort

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &p)
    {
        vector<int> adj[n];

        vector<int> inDegree(n, 0);
        queue<int> q;

        for (int i = 0; i < p.size(); i++)
        {
            int a = p[i][0];
            int b = p[i][1];

            adj[b].push_back(a);
        }

        for (int i = 0; i < n; i++)
        {
            for (int it : adj[i])
                inDegree[it]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        vector<int> topo;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }

        if (topo.size() == n)
            return topo;

        return {};
    }
};