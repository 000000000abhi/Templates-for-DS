#include <bits/stdc++.h>
using namespace std;

class TopoSort {
public:
    vector<int> topo(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n);
        vector<int> indg(n, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indg[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indg[i] == 0) q.push(i);
        }

        vector<int> res;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);

            for (auto& nei : adj[node]) {
                if (--indg[nei] == 0) q.push(nei);
            }
        }

        return res.size() == n ? res : vector<int>(); // If cycle exists, return empty vector
    }
};
