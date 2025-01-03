// POTD Jan'3, 2024
// Jan'3, 2024 11:51 pm

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n= nums.size(), ans=0;
        // long long sum= accumulate(nums.begin(), nums.end(), 0);
        // if(sum%2){
        //     if(sum<0)sum--;
        //     else sum++;
        // }
        vector<long long>pre(n+1, 0);
        vector<long long>suf(n+1, 0);

        for(int i=0; i<n; i++){
            pre[i+1]= pre[i]+nums[i];
            suf[n-1-i]= suf[n-i] + nums[n-1-i];
        }

        for(int i=0;i<n-1;i++){
            if(pre[i+1]>= suf[i+1]){
                ans++;
            }
        }
        return ans;
    }
};

// 12 min