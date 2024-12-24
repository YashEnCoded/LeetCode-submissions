// Dec'24, 2024 11:01 pm

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();

        vector<int>dp(n+1, 0);
       dp[n-1]=1;

        for(int i=n-2; i>=0; i--){
            bool ans= false;
            for(int j=1; j<= nums[i] && i+j<n; j++){
                ans|= dp[i + j];
            }

            dp[i] = ans;
        }

        return dp[0];
        // return solve(0, nums, dp);
    }
};

// 6 min

    // bool solve(int i, vector<int>&nums){
    //     int n= nums.size();
    //     if(i>=n-1){
    //         return true;
    //     }

    //     bool ans= false;
    //     for(int j=1; j<= nums[i]; j++){
    //         ans|= solve(i + j, nums);
    //     }

    //     return ans;
    // }