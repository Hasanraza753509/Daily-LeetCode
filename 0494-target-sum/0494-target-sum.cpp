class Solution {
public:
    int recursion(int index,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(index==0){
            if(target==nums[0] && nums[0]==0)return 2;
            if(target==0 || target==nums[0])return 1;
            return 0;
        }
        if(dp[index][target]!=-1)return dp[index][target];
        
        int minus=recursion(index-1,target,nums,dp);
        int plus=0;
        if(nums[index]<=target){
            plus=recursion(index-1,target-nums[index],nums,dp);
        };
        return dp[index][target]=minus+plus;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        
        int sum=0;
        
        for(int i=0;i<n;i++){
            
            sum=nums[i]+sum;
        }
        if(sum<abs(target) || (sum-target)%2)return 0;
        int required=sum-abs(target);
        vector<vector<int>> dp(n,vector<int>(required+1,-1));
        
        int ans=recursion(n-1,required/2,nums,dp);
        return ans;
        
    }
};