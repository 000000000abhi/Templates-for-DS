#include<bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unionByRank(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[px] = py;
            rank[py]++;
        }
    }
};

class MST {
public:
    int kruskal(int n, vector<pair<int, pair<int, int>>>& edges) {
        DSU ds(n);
        sort(edges.begin(), edges.end());

        int wt = 0;
        for (auto& i : edges) {
            int x = ds.find(i.second.first);
            int y = ds.find(i.second.second);
            int cwt = i.first;

            if (x == y) continue;
            wt += cwt;
            ds.unionByRank(x, y);
        }
        return wt;
    }
};
