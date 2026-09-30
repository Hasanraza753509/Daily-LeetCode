class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<vector<int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxtime =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    
                }
            }
        }
        while(!q.empty()){
            
            int row=q.front().first[0];
            int col=q.front().first[1];
            
            int time=q.front().second;
            q.pop();
            maxtime=max(maxtime,time);
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},time+1});
                    vis[nrow][ncol]=1;
                }
            }


        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    return -1;
                }
            }
        }
        return maxtime;
        
    }
};