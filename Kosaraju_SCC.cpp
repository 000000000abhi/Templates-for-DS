#include <bits/stdc++.h>
using namespace std;

class Kosaraju {
public:
    void dfs1(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
        vis[node] = true;
        for (auto& nei : adj[node]) {
            if (!vis[nei]) dfs1(nei, adj, vis, st);
        }
        st.push(node);
    }

    void dfs2(int node, vector<vector<int>>& revAdj, vector<bool>& vis, vector<int>& scc) {
        vis[node] = true;
        scc.push_back(node);
        for (auto& nei : revAdj[node]) {
            if (!vis[nei]) dfs2(nei, revAdj, vis, scc);
        }
    }

    vector<vector<int>> findSCCs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n), revAdj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);  
            revAdj[e[1]].push_back(e[0]);  
        }

        vector<bool> vis(n, false);
        stack<int> st;

        // Step 1: Perform DFS and store nodes in stack by finish time
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs1(i, adj, vis, st);
        }

        fill(vis.begin(), vis.end(), false);  // Reset visited array
        vector<vector<int>> sccList;

        // Step 2: Process nodes in order of stack using the reversed graph
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                vector<int> scc;
                dfs2(node, revAdj, vis, scc);
                sccList.push_back(scc);
            }
        }                                         // if we just have to return the count then take a counter and icrement for the number of components (times dfs2 is called).
        return sccList;
    }
};
