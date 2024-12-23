// Dec'13, 2024 04:21 pm

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();

        long long ans=0, mod=1e9+7;

        int l=0, r=n-1;
        while(l<r){
            long long cur= (r-l)*(min(height[l], height[r]));
            ans= max(cur, ans);
            if(height[l]<height[r]){
                l++;
            }
            else {
                r--;
            }
        }

        return ans;

    }
};