// POTD Jan'13, 2025
// Jan'13, 2025 04:37 pm

class Solution {
public:
    int minimumLength(string s) {
        int n= s.size(), ans=0;
        vector<int>cnt(27, 0);
        for(auto it:s){
            cnt[it-'a']++;
        }
        for(auto it:cnt){
            ans+= it==0 ? 0 : 2 - it%2;
        }

        return ans;
    }
};

// 4 min