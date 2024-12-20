// Dec'20, 2024 01:24 pm

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pre= 1, suc=1;
        int ans= nums[0];

        for(int i=0;i<n;i++){
            if(!pre)pre=1;
            if(!suc)suc=1;

            pre*=nums[i];
            suc*=nums[n-1-i];
            ans=max(ans, max(pre, suc));
        }
        return ans;
    }
};

// 25 min