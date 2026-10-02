class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        queue<int> q;
        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int> order;
        int count=0;
        while(!q.empty()){
            int element=q.front();
            q.pop();
            for(int i=0;i<prerequisites.size();i++){
                if(prerequisites[i][1]==element){
                    indegree[prerequisites[i][0]]--;
                    if(indegree[prerequisites[i][0]]==0)q.push(prerequisites[i][0]);
                }
            }
            count++;
            order.push_back(element);
        }
        if(count==numCourses)return order;
        return {};
        
    }
};