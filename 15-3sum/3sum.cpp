// Dec'23, 2024
//Dec'23, 2024 08:00 pm

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            
            int l=i+1, r=n-1;
            while(l<r){
                int sum= nums[i]+ nums[l]+ nums[r];
                if(sum==0){
                    st.insert({nums[i], nums[l], nums[r]});
                    // break;
                    l++, r--;
                }
                else if(sum>0){
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};

// 15 min