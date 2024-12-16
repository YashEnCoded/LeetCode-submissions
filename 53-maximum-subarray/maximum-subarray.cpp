// Dec'16, 2024 06:32 pm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();

        int l=0, j=0, mxsum= *max_element(nums.begin(), nums.end()), localSum=0;
        if(mxsum<0)return mxsum;

        while(j<n){
            localSum= max(0, localSum+ nums[j]);
            mxsum= max(localSum, mxsum);
            j++;
        }

        return mxsum;
    }
};

// 15 min