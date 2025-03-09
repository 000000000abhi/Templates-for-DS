#include <bits/stdc++.h>
using namespace std;

class TopoSort {
public:
    void solve(vector<vector<int>>& adj, int it, vector<bool>& vis, stack<int>& st) {
        vis[it] = true;
        for (auto i : adj[it]) {
            if (!vis[i])
                solve(adj, i, vis, st);
        }
        st.push(it);
    }

    vector<int> topo(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> vis(n, false);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                solve(adj, i, vis, st);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
