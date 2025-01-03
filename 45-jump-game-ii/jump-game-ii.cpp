// Striver Greedy
// Jan'2, 2024 06:12 pm


class Solution {
public:
    int jump(vector<int>& nums) {
        int n= nums.size();

        int jumps=0;
        int l=0, r=0;
        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest= max(farthest, i + nums[i]);
            }
            l= r+1;
            r= farthest;
            jumps+=1;
        }

        return jumps;
    }
};

// 1 hour 15 min