// Dec'23, 2024 08:54 pm

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;

        for(int i=0;i<=n;i++){
            int cnt=0, cur=i;
            while(cur){
                cnt+= cur & 1;
                cur/=2;
            }
            ans.push_back(cnt);
        }
        return ans; 
    }
};

// 5 min