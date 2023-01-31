// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

class Solution
{
public:
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Set will store the dist of node and node value in increasing manner
        set<pii> st;

        // insert dist and source
        st.insert({0, s});

        vector<int> distance(v, INT_MAX);

        // initialize source with dist 0
        distance[s] = 0;

        while (not st.empty())
        {
            pii firstElement = *(st.begin());

            int dist = firstElement.first;
            int node = firstElement.second;

            st.erase(firstElement);

            for (auto it : adj[node])
            {
                int itNode = it[0];
                int itDist = it[1];
                int newDistance = itDist + dist;

                // if old distance of current node > newDistance
                if (distance[itNode] > newDistance)
                {
                    // check whether if their is already a node of same value in set
                    auto it = st.find({distance[itNode], itNode});

                    if (it != st.end())
                        st.erase(it);

                    distance[itNode] = newDistance;
                    st.insert({newDistance, itNode});
                }
            }
        }

        return distance;
    }
};
