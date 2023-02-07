// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution
{
public:
    // Topological sort
    vector<int> topoSort(int v, vector<int> adj[])
    {
        vector<int> inDegree(v, 0);

        for (int i = 0; i < v; i++)
        {
            for (int node : adj[i])
                inDegree[node]++;
        }

        queue<int> q;
        for (int i = 0; i < v; i++)
            if (inDegree[i] == 0)
                q.push(i);

        vector<int> ans;

        while (!q.empty())
        {
            int f = q.front();
            // cout << f <<"\n";
            ans.push_back(f);
            q.pop();

            for (int it : adj[f])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }

        return ans;
    }

    string findOrder(string dict[], int n, int k)
    {
        vector<int> adj[k];

        for (int i = 0; i < n - 1; i++)
        {
            string first = dict[i];
            string second = dict[i + 1];

            int len = min(first.size(), second.size());

            for (int j = 0; j < len; j++)
            {
                if (first[j] != second[j])
                {
                    adj[first[j] - 'a'].push_back(second[j] - 'a');
                    break;
                }
            }
        }

        // for(int i=0; i<k; i++) {
        //     cout << i << " -> ";
        //     for(auto it:adj[i])
        //         cout << it << " ";
        //     cout << "\n";
        // }

        vector<int> topo = topoSort(k, adj);

        string ans = "";
        for (int vv : topo)
            ans += char(vv + 'a');

        // cout << ans << '\n';
        return ans;
    }
};