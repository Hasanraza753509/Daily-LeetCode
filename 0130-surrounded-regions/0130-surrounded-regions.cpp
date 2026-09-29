class Solution {
public:
void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board,int n,int m){
    vis[row][col]=1;
    int delrow[]={-1,0,1,0};
    int delcol[]={0,-1,0,1};

    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
            dfs(nrow,ncol,vis,board,n,m);

        }
    }
}
void solve(vector<vector<char>>& board) {
    int n=board.size();
    int m=board[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    //dfs on edges
    int traverserow[2]={0,n-1};
    int traversecol[2]={0,m-1};

    for(auto it:traverserow){
        for(int i=0;i<m;i++){
            if(board[it][i]=='O' && !vis[it][i]){
                dfs(it,i,vis,board,n,m);
            }
        }
    }
    for(auto it:traversecol){
        for(int i=0;i<n;i++){
            if(board[i][it]=='O' && !vis[i][it]){
                dfs(i,it,vis,board,n,m);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O' && !vis[i][j]){
                board[i][j]='X';
            }
        }
    }

    
}
};