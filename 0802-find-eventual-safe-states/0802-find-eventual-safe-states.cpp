class Solution {
public:
    bool dfs(int i,vector<int>& vis,vector<int>& pathvis,vector<vector<int>>& graph,queue<int>& nodes){
        vis[i]=1;
        pathvis[i]=1;
        nodes.push(i);
        for(auto it:graph[i]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,graph,nodes)){
                    return true;
                }
                
                
            }
            else if(pathvis[it]==1){
                return true;
            }
        }
        pathvis[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),0);
        vector<int> pathvis(graph.size(),0);
        vector<int> safe;
        queue<int> nodes;
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,graph,nodes);
            }
        }
        for(int i=0;i<graph.size();i++){
            if(pathvis[i]==0){
                safe.push_back(i);
            }
        }
        
        return safe;
        
    }
};