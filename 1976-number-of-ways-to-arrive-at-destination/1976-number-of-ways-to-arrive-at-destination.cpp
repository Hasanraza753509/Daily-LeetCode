class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        //[{dest,time}]
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
         // {distance, node}
        priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        //{step,node}
        while(!pq.empty()){
            long long steps=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();
            for(auto it:adj[node]){
                int dest=it.first;
                int cost=it.second;
                if(steps+cost<dist[dest]){
                    dist[dest]=steps+cost;
                    
                    ways[dest]=ways[node];
                    pq.push({steps+cost,dest});


                }
                else if((steps+cost)==dist[dest]){
                    ways[dest]=(ways[dest]+ways[node])%1000000007;
                }
            }


        }

        return ways[n-1];
        
    }
};