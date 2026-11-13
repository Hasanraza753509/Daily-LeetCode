class Solution {
public:
     int profit(int index,bool buy,vector<vector<vector<int>>>& dp,vector<int>& prices,int cap){
        if(index==prices.size())return 0;
        if(cap==0)return 0;
        if(dp[index][cap][buy]!=-1)return dp[index][cap][buy];
        int profitsum=0;
        if(buy){
            profitsum=max((-prices[index]+profit(index+1,0,dp,prices,cap)),profit(index+1,1,dp,prices,cap));

        }
        else{
            profitsum=max(prices[index]+profit(index+1,1,dp,prices,cap-1),0+profit(index+1,0,dp,prices,cap));
        }
        return dp[index][cap][buy]=profitsum;
    }
    
        
        
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(k+1,vector<int>(2,-1)));
        return profit(0,1,dp,prices,k);
        
    }
};