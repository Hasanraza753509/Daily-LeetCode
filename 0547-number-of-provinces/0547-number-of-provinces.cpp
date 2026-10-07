class disjoint{
    vector<int> parent,size;
public:
    disjoint(int n){
        for(int i=0;i<=n;i++){
            parent.push_back(i);
        }
        for(int i=0;i<=n;i++){
            size.push_back(1);
        }
    }
    
    int  findUpar(int node){
        if(parent[node]==node)return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionbysize(int u, int v){
        if(findUpar(u)==findUpar(v))return;
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(size[pu]>size[pv]){
            parent[pv]=parent[pu];
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=parent[pv];
            size[pv]+=size[pu];
        }
    }

};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        disjoint ds(n);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                if(ds.findUpar(it)!=ds.findUpar(i)){
                    ds.unionbysize(i,it);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(ds.findUpar(i)==i)count++;
        }
        return count;
        
    }
};