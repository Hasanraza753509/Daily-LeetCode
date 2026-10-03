class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,(int)strs[i].size());
        }
        string ans="";
        int count=0;
        for(int i=0;i<mini;i++){
            char s=strs[0][i];
            for(int j=1;j<n;j++){
                if(strs[j][i]!=s){
                    return ans;
                }

                    
                
            }
            
            ans=ans+strs[0][i];
        }
        return ans;
        
    }
};