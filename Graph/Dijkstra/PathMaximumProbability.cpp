// Apply Dijkstra
// Here we will find larget weight path not shortest one

class Solution {
    void print(priority_queue<pair<double, int>> pq) {
        while(!pq.empty()) {
            cout << pq.top().second << " -> " << pq.top().first << "\n";
            pq.pop();
        }
    }
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];

        for(int i=0 ;i<edges.size(); i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});

        vector<double> dist(n, 0.0);
        dist[start] = 1.0;

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            double prob = (double)p.first;
            int node = p.second;

            for(pii adjPair : adj[node]) {
                int adjNode = adjPair.first;
                double adjProb = adjPair.second;

                double newProb = prob * adjProb;

                if(newProb > dist[adjNode]) {
                    dist[adjNode] = newProb;
                    pq.push({newProb, adjNode});
                }
            }
        }

        if(dist[end] == 1e9)
            return 0;
        
        return dist[end];
    }
};
