// Dec'16, 2024 06:16 pm

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int>mp;

        for(auto it:nums){
            if(mp.contains(it)){
                return true;
            }
            mp[it]++;
        }

        return false;
    }
};

// 01.45 min