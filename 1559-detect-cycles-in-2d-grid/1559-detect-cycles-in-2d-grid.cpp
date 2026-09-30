class Solution {
public:
    bool  dfs(int n,int m,vector<vector<char>>& grid,vector<vector<pair<int, vector<int>>>>& vis,int i,int j,int& count,int parentrow,int parentcol){
        vis[i][j].first=1;
        vis[i][j].second={parentrow,parentcol};
        int row=i;
        int col=j;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==grid[row][col] && vis[nrow][ncol].first==0){
                if(dfs(n,m,grid,vis,nrow,ncol,count,row,col)){
                    return true;

                }
            }
            else if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==grid[row][col] && vis[nrow][ncol].first==1 && (nrow!=parentrow || ncol!=parentcol)){
                count++;
                return true;
            }
        }
        return false;

    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<pair<int, vector<int>>>> vis(n, vector<pair<int, vector<int>>>(
        m, {0, vector<int>(2, 0)}));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j].first){
                    if(dfs(n,m,grid,vis,i,j,count,-1,-1)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};