// Dec'16, 2024 05:56 pm

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mod= 1e9+7;
        int n= nums.size();
        vector<long long> pre(n+2, 1), suc(n+2, 1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            // pre[i+1]= ((pre[i]%mod) *(nums[i]%mod))%mod;
            pre[i+1]= pre[i]*nums[i];

            // suc[n-1-i]= ((suc[n-i]%mod)* (nums[n-1-i]%mod))%mod;
            suc[n-1-i]= suc[n-i]* nums[n-1-i];
        }

        for(int i=0;i<n;i++){
            // long long cur= ((pre[i]%mod)* (suc[i+1]%mod));
            ans[i]= (pre[i]* suc[i+1]);
        }
        return ans;

    }
};

// 17 min