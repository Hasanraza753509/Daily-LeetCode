class Solution {
public:
    bool bfs(int i,vector<int>& vis,vector<vector<int>>& graph,queue<int>& q){
        while(!q.empty()){
            int first=q.front();
            q.pop();
            for(auto it:graph[first]){
                if(vis[it]==-1){
                    vis[it]=!vis[first];
                    q.push(it);
                }
                else if(vis[it]==vis[first]){
                    return false;
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        vector<int> vis(graph.size(),-1);
       
        for(int i=0;i<graph.size();i++){
            if(vis[i]==-1){
                q.push(i);
                vis[i]=0;
                if(!bfs(i,vis,graph,q)){
                    return false;
                }
            }
        }
        return true;
        
    }
};