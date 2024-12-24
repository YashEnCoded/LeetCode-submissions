// Dec'24, 2024 07:08 pm

class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        
        vector<int>pre(3, 0), cur(3, 0);
        pre[1]= nums[0];
        cur[1]= nums[0];

        for(int i=1;i<n;i++){
            cur[0] = max(pre[1], pre[0]);
            cur[1] = nums[i] + pre[0];

            pre=cur;
        }
        
        return max(cur[0], cur[1]);
        // int ans= max(solve(n-1, 1, nums), solve(n-1, 0, nums));
        // return ans;
    }
};

// 10 min

    // int solve(int i, int lastPick, vector<int>nums){
    //     int n= nums.size();
    //     if(i==0){
    //         return !lastPick ? nums[0] : 0;
    //     }

    //     int notTake= solve(i-1, 0, nums);
    //     int take= 0;
    //     if(!lastPick){
    //         take= nums[i] + solve(i-1, 1, nums);
    //     }

    //     return max(take, notTake);
    // }