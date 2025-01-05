// Jan'5, 2025 06;40 pm

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses, 0);

        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses; i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        stack<int>st;
        for(int i=0;i<numCourses; i++){
            if(indegree[i]==0){
                st.push(i);
            }
        }

        vector<int>ans;
        while(!st.empty()){
            int node= st.top();
            st.pop();
            ans.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    st.push(it);
                }
            }
        }

        if(ans.size()== numCourses)return ans; 
        return {};
    }
};

// 7 min