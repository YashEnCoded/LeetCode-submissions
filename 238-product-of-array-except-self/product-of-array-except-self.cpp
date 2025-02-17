// Dec'16, 2024 05:56 pm

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n, 1);
        
        int left=1, right=1;

        for(int i=0;i<n;i++){
            ans[i]*=left;
            left*=nums[i];
            
            ans[n-1-i]*=right;
            right*=nums[n-1-i];
        }
        return ans;

    }
};

// 17 min
// Easier approach