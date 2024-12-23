// Dec'23, 2024 05:20 pm

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int l=0, r=n-1, ans= -1, mn= nums[0], mnInd= 0;

        while(l<=r){
            int mid= l+ (r-l)/2;

            if(nums[l]<= nums[r]){
                if(mn>= nums[l]){
                    mn= nums[l];
                    mnInd= l;
                }
                break;
            }
            
            if(nums[l]<= nums[mid]){
                if(mn>= nums[l]){
                    mn= nums[l];
                    mnInd= l;
                }
                l= mid+1;
            }
            else {
                if(mn>= nums[mid]){
                    mn= nums[mid];
                    mnInd=mid;
                }
                r= mid-1;
            }
        }

        cout<<mnInd<<" "<<mn<<endl;
        if(target>= nums[mnInd] && target<= nums[n-1]){
            l= mnInd, r=n-1;

            while(l<=r){
                int mid= l+(r-l)/2;

                if(target> nums[mid]){
                    l= mid+1;
                }
                else if(target< nums[mid]){
                    r=mid-1;
                }
                else {
                    ans= mid;
                    break;
                }
            }
        }
        else if(mnInd>0 && target>= nums[0] && target<= nums[mnInd-1]){
            l=0, r= mnInd-1;

            while(l<=r){
                int mid= l+(r-l)/2;

                if(target> nums[mid]){
                    l= mid+1;
                }
                else if(target< nums[mid]){
                    r=mid-1;
                }
                else {
                    ans= mid;
                    break;
                }
            }
        }

        return ans;
    }
};

// 11 min