// Dec'25, 2024 09:00 pm

class Solution {
    bool solve(int node, vector<vector<int>>& graph, vector<int>&color, vector<int>&vis){
        queue<int>q;
        color[node]=0;
        vis[node]=1;
        q.push(node);

        while(!q.empty()){
            int node= q.front();
            int col= color[node];

            q.pop();
            for(auto neighbor: graph[node]){
                if( color[neighbor] == -1){
                    color[neighbor]= !color[node];
                    if(!vis[neighbor]){
                        q.push(neighbor);
                        vis[neighbor]=1;
                    }
                }
                else if(color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>color(n ,-1);

        vector<vector<int>> adj= graph;
        vector<int>vis(n, 0);

        int node=0;
        for(int i=0;i<n;i++){
            if(!vis[i] && graph[i].size()!=0){
                if(!solve(i, graph, color, vis)){
                    return false;
                }
            }
        }
        
        return true;
    }
};

// 20 min