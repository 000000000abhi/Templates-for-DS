#include <bits/stdc++.h>
using namespace std;

class BellmanFord {
public:
    vector<int> findShortestPath(int n, vector<vector<int>>& edges, int src) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        for (int i = 0; i < n - 1; i++) {
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1], wt = edge[2];
                if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                return {}; // Negative cycle detected
            }
        }
        return dist;
    }
};
