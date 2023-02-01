// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

/*
SCC:-
    A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.

    Kosaraju's Algorithm:-
        Step 1:- Sort all nodes on the basis of finishing time (Topological sort)
        Step 2:- Take transpose of a graph (reverse each edge of a graph)
        Step 3:- Apply dfs on Topological sort and count SCC
*/

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:

    // Topoplogical sort
    void topo(int node, vector<bool> &visited, vector<int> adj[], stack<int> &st)
    {
        visited[node] = true;

        for (int it : adj[node])
            if (visited[it] == false)
                topo(it, visited, adj, st);

        st.push(node);
    }

    // dfs on transpose graph
    void dfs(int node, vector<bool> &visited, vector<int> transpose[])
    {
        visited[node] = true;

        for (int it : transpose[node])
            if (visited[it] == false)
                dfs(it, visited, transpose);
    }

    void printAdjList(vector<int> adj[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " -> ";
            for (int it : adj[i])
            {
                cout << it << " ";
            }
            cout << "\n";
        }
    }

    // Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<int> adj[])
    {
        // to store the topological sort
        stack<int> st;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
            if (visited[i] == false)
                topo(i, visited, adj, st);

        // printAdjList(adj, n);

        // Transpose of a graph
        vector<int> transpose[n];
        for (int i = 0; i < n; i++)
        {
            for (int it : adj[i])
            {
                transpose[it].push_back(i);
            }
        }

        // printAdjList(transpose, n);

        for (int i = 0; i < n; i++)
            visited[i] = false;

        int scc = 0;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();

            if (!visited[top])
            {
                scc++;
                dfs(top, visited, transpose);
            }
        }

        return scc;
    }
};
