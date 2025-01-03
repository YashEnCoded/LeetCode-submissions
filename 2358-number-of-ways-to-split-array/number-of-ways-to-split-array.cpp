// POTD Jan'3, 2024
// Jan'4, 2024 12:02 pm

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n= nums.size(), ans=0;
        long long sum= accumulate(nums.begin(), nums.end(), 0LL);
        long long curSum=0;
        vector<int>pre(n+1, 0);
        for(int i=0; i<n-1; i++){
            curSum+=nums[i];
            if(2* curSum>= sum)ans++;
        }

        return ans;
    }
};

// 13 min