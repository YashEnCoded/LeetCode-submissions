// Dec'16, 2024 04:25 pm
// STRIVER Blind 75

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();

        vector<int>ans(2, -1);
        map<int, int>mp;
        for(int i=0;i<n;i++){
            int pos= target-nums[i];

            if(mp.contains(pos) && nums[i]+ nums[mp[pos]]== target){
                ans[0]=i, ans[1]= mp[pos];
                return ans;
            }
            mp[nums[i]]=i;
        }

        return ans;
    }
};

// 6 min