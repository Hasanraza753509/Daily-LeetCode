class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int dist=q.front().second;
            q.pop();
            if(word==endWord){
                return dist;
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){
                        q.push({word,dist+1});
                        s.erase(word);
                    }
                    

                }
                word[i]=original;
            }

        }
        return 0;

        
    }
};