// POTD Dec'21, 2024
//Dec'21, 2024 09:44 pm

class Solution {
private:
    int ans=0;
private:
    long long dfs(int i, vector<int>&vis, vector<int>&val, vector<int>adj[], int k){
        vis[i]=1;
        long long sum=0, flag=0;
        for(auto it:adj[i]){
            if(!vis[it]){
                long long temp=dfs(it, vis, val, adj, k);
                sum+=temp;
            }
        }
        sum+=val[i];
        ans+= sum%k==0;
        return sum%k;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+1, 0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long cur=dfs(i, vis, values, adj, k);
            }
        }
        return ans;
    }
};

// Earlier solved copied