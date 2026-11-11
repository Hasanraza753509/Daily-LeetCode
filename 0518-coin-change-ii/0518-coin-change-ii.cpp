class Solution {
public:
    int recursion(int index,int target,vector<int>& coins,vector<vector<int>>& dp){
        if(index==0){
            if(target==0 || target%coins[0]==0)return 1;
            return 0;
        }
        if(dp[index][target]!=-1)return dp[index][target];
        int nottake=recursion(index-1,target,coins,dp);
        int take=0;
        if(coins[index]<=target){
            take=recursion(index,target-coins[index],coins,dp);
        }
        return dp[index][target]=take+nottake;
    }
    int change(int target, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int ans=recursion(n-1,target,coins,dp);
        return ans;
        

        
    }
};