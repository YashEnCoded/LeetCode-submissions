// Dec'24, 2024 02:35 am

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();

        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        vector<int>prev(n+1, 0), cur(n+1, 0);

        // int ans= solve(n-1, nums, n, dp);
        // return max(ans, 1);

        for(int i=0;i<=n; i++){
            if(i== n || nums[0]<nums[i]){
                prev[i]=1;
            }
            else {
                prev[i]= 0;
            }
        }

        for(int i=1;i<n;i++){
            for(int pre=i+1;pre<=n; pre++){
                int notTake= prev[pre];
                int take= 0;
                if(pre==n || nums[i]< nums[pre]){
                    take= 1 + prev[i];
                }

                cur[pre]= max(take, notTake);
            }
            prev= cur;
        }

        int ans= cur[n];
        for(auto it:cur){
            ans= max(ans, it);
        }
        return max(ans, 1);
    }
};

// 25 min

/*
    int solve(int i, vector<int>&nums, int pre, vector<vector<int>>&dp){
        int n= nums.size();

        if(i==0){
            if(pre==n || nums[i]< nums[pre]){
                return 1;
            }
            else {
                return 0;
            }
        }

        if(dp[i][pre]!=-1){
            return dp[i][pre];
        }
        int notTake= solve(i-1, nums, pre, dp);
        int take= 0;
        if(pre==n || nums[i]< nums[pre]){
            take= 1 + solve(i-1, nums, i, dp);
        }

        return dp[i][pre]= max(take, notTake);
    }
*/