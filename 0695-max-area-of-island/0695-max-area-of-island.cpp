class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>& vis,int& area,int& maxarea){
        vis[row][col]=1;
        area=area+1;
        int n=grid.size();
        int m=grid[0].size();
        maxarea=max(area,maxarea);
        int delrow[]={1,0,-1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,grid,vis,area,maxarea);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        int maxarea=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    dfs(i,j,grid,vis,area,maxarea);
                    area=0;
                }
            }
        }
        return maxarea;
        
    }
};