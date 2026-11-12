class Solution {
public:
    bool recursion(int i,int j,string& s,string& p,vector<vector<int>>& dp){
        if(i<0 && j<0)return true;
        if(j<0 && i>=0)return false;
        if(i<0 && j>=0){
            while(j>=0){
                if(p[j]!='*')return false;
                j--;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==p[j] || p[j]=='?') return dp[i][j]=recursion(i-1,j-1,s,p,dp);
        if(p[j]=='*')return dp[i][j]=recursion(i,j-1,s,p,dp) | recursion(i-1,j,s,p,dp);
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return recursion(s.size()-1,p.size()-1,s,p,dp);
        
    }
};