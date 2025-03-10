#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> low, disc;
    unordered_set<int> ans;
    int t = 0; // Time counter

    void solve(int src, int par, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[src] = true;
        disc[src] = low[src] = t++;
        int children = 0;

        for (auto i : adj[src]) {
            if (i == par) continue;
            if (!vis[i]) {
                children++;
                solve(i, src, adj, vis);
                low[src] = min(low[src], low[i]);

                if (par != -1 && disc[src] <= low[i]) {
                    ans.insert(src);
                }
            } else {
                low[src] = min(low[src], disc[i]);
            }
        }

        if (par == -1 && children > 1) ans.insert(src);
    }

    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);
        low.resize(n, 0);
        disc.resize(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) solve(i, -1, adj, vis);
        }

        return vector<int>(ans.begin(), ans.end()); // Convert set to vector
    }
};
