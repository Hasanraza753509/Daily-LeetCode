class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> price(n,1e9);
        queue<vector<int>> q;
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});

        }
        price[src]=0;
        q.push({0,src,0});
        while(!q.empty()){
            int stops=q.front()[0];
            int source=q.front()[1];
            int currcost=q.front()[2];
            
            q.pop();
            if(stops>k)continue;


            for(auto it:adj[source]){
                int dest=it.first;
                int cost=it.second;
                if(cost+currcost<price[dest] && stops<=k){
                    price[dest]=cost+currcost;
                    q.push({stops+1,dest,cost+currcost});
                }
            }

        }
        if(price[dst]==1e9){
            return -1;
        }
        return price[dst];

        

        
    }
};