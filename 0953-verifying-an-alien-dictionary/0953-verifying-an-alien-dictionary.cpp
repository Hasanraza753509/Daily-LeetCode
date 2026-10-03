class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int count=0;
        vector<int> value(26,0);
        for(int i=0;i<order.size();i++){
            value[order[i]-'a']=i;

        }
        for(int i=0;i<words.size()-1;i++){
            bool decide=false;
            for(int j=0;j<min(words[i].size(),words[i+1].size());j++){
                if(value[words[i][j]-'a']<value[words[i+1][j]-'a']){
                    decide=true;
                    break;
                }
                if(value[words[i][j]-'a']>value[words[i+1][j]-'a']){
                    return false;
                }
               
            }
            if(!decide && words[i].size()>words[i+1].size()){
                return false;
            }
            
        }
        
        return true;
        
    }
};