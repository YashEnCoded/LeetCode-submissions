// Jan'4, 2024 10:31 pm

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n= nums.size();
        long ans=0;

        for(int i=0;i<n;i++){
            int ni= abs(nums[i]);
            if(nums[ni]<0){
                ans= ni;
            }
            nums[ni]=(-nums[ni]);
        }
        for(int i=0;i<n;i++){
            nums[i]= abs(nums[i]);
        }
        return ans;
    }
};

// 12 min