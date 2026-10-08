class Solution {
public:
    void dfs(int node,int parent,int timer,vector<int>& vis,vector<int> adj[],int tin[],int low[],vector<vector<int>>& bridges){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent)continue;
            if(vis[it]==0){
                dfs(it,node,timer,vis,adj,tin,low,bridges);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node])bridges.push_back({it,node});

            }
            else{
                low[node]=min(low[it],low[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> vis(n,0);
        vector<vector<int>> bridges;
        int tin[n];
        int low[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int timer=1;
        dfs(0,-1,timer,vis,adj,tin,low,bridges);
        return bridges;
        
    }
};