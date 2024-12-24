// Dec'24, 2024 06:43 pm

class Solution {
    void solve(int i, vector<int>& candidates, int target, vector<int>v, vector<vector<int>>&ans, vector<vector<int>>&dp){
        int n= candidates.size();
        if(!target){
            ans.push_back(v);
            return;
        }
        if(i<0){
            return;
        }

        // Not Take
        solve(i-1, candidates, target, v, ans, dp);
        // Take
        if(candidates[i]<= target){
            v.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], v, ans, dp);
        }
        dp[i][target]= 1;
        return ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n= candidates.size();

        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        vector<vector<int>>ans;
        solve(n-1, candidates, target, {}, ans, dp);
        return ans;
    }
};

// 16 min