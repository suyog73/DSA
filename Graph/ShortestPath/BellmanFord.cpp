// https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

/*
Used to detect negative cycles

Apply on directed graph (to apply BF algo on undirected graph convert it into directed graph)

Relax all edges n-1 times as follow
    --> if(dist[u] + wt < dist[v])
            dist[v] = dist[u] + wt;

After relaxing all edges (n-1) times, relax edges one more time and if any distance gets updated then their exists a negative weight cycle in a graph (We cannot find shortest path)

*/

#include <vector>
using namespace std;

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex to start traversing graph with
     *   n: number of vertices
     */
    vector<int> bellman_ford(int n, vector<vector<int>> &edges, int src)
    {
        // As some node may not be visited so mark them to 1e8 as told in que
        vector<int> shortedDistance(n, 1e8);

        // source distance is 0
        shortedDistance[src] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (vector<int> e : edges)
            {
                int u = e[0];
                int v = e[1];
                int wt = e[2];

                // relaxing edges n-1 times
                if (shortedDistance[u] != 1e9 and shortedDistance[v] > shortedDistance[u] + wt)
                    shortedDistance[v] = shortedDistance[u] + wt;
            }
        }

        bool isNegCycle = false;

        // checking negative weight cycle
        for (vector<int> e : edges)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if (shortedDistance[u] != 1e9 and shortedDistance[v] > shortedDistance[u] + wt)
                isNegCycle = true;
        }

        if (isNegCycle)
            return {-1};

        return shortedDistance;
    }
};
