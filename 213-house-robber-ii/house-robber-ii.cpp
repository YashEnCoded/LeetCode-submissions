// Dec'12, 2024 07:37 pm

class Solution {
    int solve(int i, int prePick, int lastPick, vector<int>&nums, vector<vector<vector<int>>>& dp){
        if(i==0){
            if(lastPick || prePick){
                return 0;
            }
            else {
                return nums[0];
            }
        }

        if(dp[i][prePick][lastPick]!= -1 ){
            return dp[i][prePick][lastPick];
        }

        int notTake=  solve(i-1, 0, lastPick, nums, dp);
        int take= 0;
        if(!prePick){
            take= nums[i] + solve(i-1, 1, lastPick, nums, dp);
        }

        return dp[i][prePick][lastPick]= max(take, notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1){
            return nums[0];
        }
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(3, vector<int>(3, -1)));
        int ans= max(solve(n-2, 0, 0, nums, dp), solve(n-2, 1, 1, nums, dp)+ nums[n-1]);

        return ans; 
    }
};

// 15 min