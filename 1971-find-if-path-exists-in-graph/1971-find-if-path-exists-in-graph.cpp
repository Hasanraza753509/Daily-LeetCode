class Solution {
public:
    bool dfs(int source,vector<vector<int>>& edges,int destination,vector<int>& vis,vector<vector<int>>& adj){
        vis[source]=1;
        if(source==destination){
            return true;
        }
        for(auto it:adj[source]){
            
            if(!vis[it]){
                if(dfs(it,edges,destination,vis,adj))return true;
            }

        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);

        }
        if(dfs(source,edges,destination,vis,adj))return true;
        return false;
        
        
    }
};