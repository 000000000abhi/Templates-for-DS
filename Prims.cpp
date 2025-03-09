
class MST {
public:
    int prims(int n, vector<vector<pair<int, int>>>& adj,int src) {
        vector<int> vis(n, 0); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int mstCost = 0;

        pq.push({0, src}); 
         
        while (!pq.empty() && edgesUsed < n) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (vis[node]) continue;
            
            vis[node] = 1;
            mstCost += wt;
          
            for (auto& [next, nextWt] : adj[node]) {
                if (!vis[next]) {
                    pq.push({nextWt, next});
                }
            }
        }
        return mstCost;
    }
};
