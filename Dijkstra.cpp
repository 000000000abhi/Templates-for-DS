
int solve(vector<vector<int>>& nums, int src) {
    int n = nums.size();
    vector<vector<pair<int, int>>> adj(n);
    
    for (auto& i : nums) {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }
    
    vector<int> vis(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, src});
    vis[src] = 0;
    
    while (!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for (auto& i : adj[node]) {
            int newnode = i.first;
            int newwt = i.second + wt;
            
            if (newwt < vis[newnode]) {
                vis[newnode] = newwt;
                pq.push({newwt, newnode});
            }
        }
    }
    
    return *max_element(vis.begin(), vis.end()); //this return the max cost to reach a node we can modify this as per our requirements.
}
