class Solution {
public:
    int minRotations(int n, string s) {
        int ptr=0;
        int minirotation=INT_MAX;
        int totalrotation=0;
        for(int j=0;j<s.size();j++){
            int digit=s[j]-'0';
            int diff=abs(ptr-digit);
            totalrotation=totalrotation+min(diff,10-diff);
            ptr=digit;

        }
        for(int i=0;i<n;i++){
            if(!i)ptr=0;
            else ptr=s[i-1]-'0';
            int count=totalrotation;
            int diff=abs(ptr-(s[i]-'0'));
            int outgoing=min(diff,10-diff);
            int diff1=abs(ptr-(s[n-1]-'0'));
            int incoming=min(diff1,10-diff1);
            count=count+incoming-outgoing;
            minirotation=min(minirotation,count);
        }
            
            
        
        return minirotation;
        
    }
};