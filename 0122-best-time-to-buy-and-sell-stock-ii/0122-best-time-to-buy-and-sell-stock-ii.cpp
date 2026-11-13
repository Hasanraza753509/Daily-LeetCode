class Solution {
public:
    int profit(int index,bool buy,vector<vector<int>>& dp,vector<int>& prices){
        if(index==prices.size())return 0;
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profitsum=0;
        if(buy){
            profitsum=max((-prices[index]+profit(index+1,0,dp,prices)),profit(index+1,1,dp,prices));

        }
        else{
            profitsum=max(prices[index]+profit(index+1,1,dp,prices),0+profit(index+1,0,dp,prices));
        }
        return dp[index][buy]=profitsum;
    }
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return profit(0,1,dp,prices);
    }
};