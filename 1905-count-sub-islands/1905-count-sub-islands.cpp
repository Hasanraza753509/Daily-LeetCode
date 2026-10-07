class Solution {
public:
    bool dfs(int row,int col,vector<vector<int>>& vis1,vector<vector<int>>& vis2,        vector<vector<int>>& grid1,vector<vector<int>>& grid2){
        vis2[row][col]=1;
        int delrow[]={0,1,0,-1};
        int delcol[]={1,0,-1,0};
        bool issubisland=grid1[row][col];
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<grid1.size() && ncol>=0 && ncol<grid1[0].size() && !vis2[nrow][ncol] && grid2[nrow][ncol]==1 ){
                if(!dfs(nrow,ncol,vis1,vis2,grid1,grid2)) issubisland=false ;
            }
           
        }
        return issubisland;
        
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        vector<vector<int>> vis1(n,vector<int>(m,0));
        
        vector<vector<int>> vis2(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis2[i][j] && grid2[i][j]==1){
                    if(dfs(i,j,vis1,vis2,grid1,grid2)){
                        count++;
                    }
                }
            }
        }
        return count;
        
    }
};