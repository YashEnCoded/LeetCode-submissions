// Dec'24, 2024 10:42 pm

class Solution {
public:
    int numDecodings(string s) {
        int n= s.size();
        vector<int> dp(n+1, 0);
        dp[n]=1;

        for(int i=n-1;i>=0; i--){
            if(s[i]== '0'){
                dp[i]= 0 ;
                continue;
            }

            int res = dp[i+1];
            if(i< n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]>='0' && s[i+1]<= '6'))){
                res+= dp[i+2];
            }
            dp[i]= res;
        }

        int ans= dp[0];
        return ans;
    }
};

// 27 min
// NeetCode YouTube soln.

    // int solve(int i, string s, vector<int>&dp){
    //     int n= s.size();
    //     if(i==n){
    //         return 1;
    //     }
        
    //     if(s[i]== '0'){
    //         return 0;
    //     }
    //     if(dp[i]!=-1){
    //         return dp[i];
    //     }
    //     int res = solve(i+1, s, dp);
    //     if(i< n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]>='0' && s[i+1]<= '6'))){
    //         res+= solve(i+2, s, dp);
    //     }
    //     return dp[i]= res;
    // }