class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid){
        vis[row][col]=1;
        int delrow[]={0,1,0,-1};
        int delcol[]={1,0,-1,0};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>0 && nrow<grid.size() && ncol>0 && ncol<grid[0].size() && grid[nrow][ncol]==0 & !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int rows[]={0,n-1};
        int cols[]={0,m-1};
        
        for( auto it:rows){
            for(int i=0;i<m;i++){
                if(!vis[it][i] && grid[it][i]==0){
                    dfs(it,i,vis,grid);
                }

            }
        }
        for( auto it:cols){
            for(int i=0;i<n;i++){
                if(!vis[i][it] && grid[i][it]==0){
                    dfs(i,it,vis,grid);
                }

            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && !grid[i][j]){
                    dfs(i,j,vis,grid);
                    count++;
                }

            }
        }
        return count;

        
    }
};