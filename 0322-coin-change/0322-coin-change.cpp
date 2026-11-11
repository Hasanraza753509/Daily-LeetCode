class Solution {
public:
    int recursion(int index,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(index==0){
            if(amount%coins[index]==0) return amount/coins[index];
            else return 1e9;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        int nottake=0+recursion(index-1,amount,coins,dp);
        int take=INT_MAX;
        if(coins[index]<=amount){
            take=1+recursion(index,amount-coins[index],coins,dp);
        }
        return dp[index][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int count=recursion(n-1,amount,coins,dp);
        if(amount==0){
            return 0;
        }
        if(n==0){
            return -1;
        }
        if(n==1){
            dp[n-1][amount]=count;
        }


        if(dp[n-1][amount]>=1e9)return -1;
        return dp[n-1][amount];

        
    }
};