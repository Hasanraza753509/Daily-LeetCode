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
    int sizes(int u){
        size[u]=size[findUpar(u)];
        return size[u];
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        disjoint ds(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int delrow[]={0,1,0,-1};
                    int delcol[]={1,0,-1,0};
                    int pnode=n*i+j;
                    for(int k=0;k<4;k++){
                        int nrow=i+delrow[k];
                        int ncol=j+delcol[k];
                        int cnode=n*nrow+ncol;
                        if(nrow<n && ncol <m && nrow>=0 && ncol>=0 && grid[nrow][ncol]==1){
                            if(ds.findUpar(pnode)!=ds.findUpar(cnode)){
                                ds.unionbysize(pnode,cnode);
                            }
                        }
                    }
                }
            }
        }
        if(ds.sizes(0)==n*m){
            return n*m;
        }
        int maxsize=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    int tempsize=1;
                    int delrow[]={0,1,0,-1};
                    int delcol[]={1,0,-1,0};
                    int pnode=n*i+j;
                    set<int>  lastvisit;
                    for(int k=0;k<4;k++){
                        int nrow=i+delrow[k];
                        int ncol=j+delcol[k];
                        int cnode=n*nrow+ncol;
                        if(nrow<n && ncol <m && nrow>=0 && ncol>=0 && grid[nrow][ncol]==1){
                            if(lastvisit.find(ds.findUpar(cnode))==lastvisit.end()){
                                lastvisit.insert(ds.findUpar(cnode));
                                tempsize+=ds.sizes(cnode);
                            }
                           
                        }
                    }
                    maxsize=max(maxsize,tempsize);

                }
            }
        }
        return maxsize;

        
        
    }
};