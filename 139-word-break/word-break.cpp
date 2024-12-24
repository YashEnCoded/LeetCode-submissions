// Dec'24, 2024 04:54 pm

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n= s.size(), m= wordDict.size();

        vector<int>dp(n+1, 0);

        // return solve(0, s, wordDict);

        dp[n]=1;

        for(int i=n-1;i>=0;i--){
            for(auto word:wordDict){
                if(i+word.length()<=n && s.substr(i, word.length())== word){
                    dp[i]= dp[i+word.size()];
                    if(dp[i])break;
                }
            }
        }

        return dp[0];
    }
};

// NeetCode YouTube soln.
// 26 min

    // bool solve(int i, string s, vector<string>&wordDict){
    //     int n= s.size();
    //     if(i==n){
    //         return true;
    //     }

    //     bool ans= false;
    //     for(auto si: wordDict){
    //         if(i+si.length()<=n && s.substr(i, si.length())== si){
    //             ans= solve(i+si.size(), s, wordDict);
    //             if(ans)break;
    //         }
    //     }

    //     return ans;
    // }