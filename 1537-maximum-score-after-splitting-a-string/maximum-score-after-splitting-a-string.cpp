// POTD Jan'1, 2025
// Jan'1, 2025 01:34 pm

class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int nz=0, nzi=0, ans=0;

        for(auto c:s){
            if(c=='0')nz++;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]=='0')nzi++;
            ans= max(ans, nzi+ n-1-i-(nz-nzi));
        }
        return ans;
    }
};

// 8 min