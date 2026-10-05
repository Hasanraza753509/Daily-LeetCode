class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            int sum=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1){
                return dist[row][col];
            }
            int rowswitch=0;
            int colswitch=1;
            for(int i=0;i<2;i++){
                int nrow=row+rowswitch;
                int ncol=col+colswitch;
                if(ncol>=0 && ncol<m && nrow>=0 && nrow<n ){
                    if(sum+grid[nrow][ncol]<dist[nrow][ncol]){
                        dist[nrow][ncol]=sum+grid[nrow][ncol];
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
                rowswitch=1;
                colswitch=0;
            }
        }
        return dist[n-1][m-1];

        
    }
};