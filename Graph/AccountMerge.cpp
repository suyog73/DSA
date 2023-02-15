// https://leetcode.com/problems/accounts-merge/

#include <bits/stdc++.h>
using namespace std;

// ---------------------Disjoint Set---------------------------//

class DisjointSet
{
    vector<int> parent, rank, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i < n + 1; i++)
            parent[i] = i;
    }

    int findParent(int u)
    {
        if (u == parent[u])
            return u;

        return parent[u] = findParent(parent[u]); // Path compression
    }

    void unionByRank(int u, int v)
    {
        int upU = findParent(u); // ultimate parent of U
        int upV = findParent(v); // ultimate parent of V

        // belonging to same component
        if (upU == upV)
            return;

        if (rank[upU] < rank[upV])
            parent[upU] = upV;

        else if (rank[upU] > rank[upV])
            parent[upV] = upU;

        else
        {
            parent[upV] = upU;
            rank[upU]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int upU = findParent(u); // ultimate parent of U
        int upV = findParent(v); // ultimate parent of V

        // belonging to same component
        if (upU == upV)
            return;

        if (size[upU] < size[upV])
        {
            parent[upU] = upV;
            size[upV] += size[upU];
        }
        else
        {
            parent[upV] = upU;
            size[upU] += size[upV];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mp.count(mail) == 0)
                    mp[mail] = i;
                else
                    ds.unionBySize(i, mp[mail]);
            }
        }

        vector<string> mergeMails[n];
        for (auto it : mp)
        {
            string mail = it.first;
            int node = ds.findParent(it.second);

            mergeMails[node].push_back(mail);
        }

        vector<vector<string>> vs;
        for (int i = 0; i < n; i++)
        {
            if (mergeMails[i].size() == 0)
                continue;

            sort(mergeMails[i].begin(), mergeMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (string mm : mergeMails[i])
                temp.push_back(mm);

            vs.push_back(temp);
        }

        return vs;
    }
};