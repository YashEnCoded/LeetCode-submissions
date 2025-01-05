// Jan'5, 2024 06:28 pm

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int cnt=0;
        while(!st.empty()){
            int node= st.top();
            st.pop();
            cnt++;

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    st.push(it);
                }
            }
        }

        return cnt== numCourses;    
    }
};

// 6 min
// Using Kahn's Algo
// Using Topo Sort by BFS