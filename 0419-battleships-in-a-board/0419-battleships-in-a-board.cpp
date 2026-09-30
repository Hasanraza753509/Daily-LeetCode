class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis,int n,int m){
        vis[row][col]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='X' && !vis[nrow][ncol]){
                dfs(nrow,ncol,board,vis,n,m);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int battleships=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X' && !vis[i][j]){
                    dfs(i,j,board,vis,n,m);
                    battleships++;
                }
            }
        }
        return battleships;
        
    }
};