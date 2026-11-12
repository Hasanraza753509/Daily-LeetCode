class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
       
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=n;
        int j=m;
        string s="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                s=str1[i-1]+s;
                i--;j--;
            }
            else if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
        string ans="";
        int k=0;int l=0;
        for(auto it:s){
            while(str1[k]!=it && k<n){
                ans=ans+str1[k];
                k++;

            }
            while(str2[l]!=it & l<m){
                ans=ans+str2[l];
                l++;
            }
            ans=ans+it;
            k++;l++;
        }
        while(k<n){
            ans=ans+str1[k];
            k++;
        }
        while(l<m){
            ans=ans+str2[l];
            l++;
        }
        return ans;
        
    }
};