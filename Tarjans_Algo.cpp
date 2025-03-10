class Solution {
public:
   vector<int>low,disc;
      vector<vector<int>>ans;
      void solve(int src,int par,vector<vector<int>>&adj,vector<bool>&vis,int t)
      {
        t++;vis[src]=1;
        disc[src]=low[src]=t;
        for(auto i:adj[src])
        { if(i==par)continue;
            if(!vis[i])
            {
                solve(i,src,adj,vis,t);
                
                low[src]=min(low[src],low[i]);
                if(disc[src]<low[i])
                {
                     ans.push_back({src,i});
                }
            }
            else
            {
            low[src]=min(low[src],low[i]);
 
            }
        }
      }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& nums) {
        vector<vector<int>>adj(n);
        for(auto i:nums)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool>vis(n,0);
        low.resize(n,0);
        disc.resize(n,0);
      solve(0,-1,adj,vis,0);
      return ans;
    }
};
