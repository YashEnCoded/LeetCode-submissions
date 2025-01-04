// POTD Jan'4, 2024
// Jan'4, 2024 09:06 pm

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n= s.size(), ans=0;
        map<char, int>mp_pre, mp_suf;
        for(int i=0;i<n;i++){
            if(mp_pre[s[i]]==0){
                mp_pre[s[i]]= i+1;
            }
            if(mp_suf[s[n-1-i]]== 0){
                mp_suf[s[n-1-i]]= n-i;
            }
        }

        for(char c='a'; c<='z'; c++){
            set<char>st;
            for(int i= mp_pre[c]; i<n && i<mp_suf[c]-1; i++){
                st.insert(s[i]);
            }
            ans+= st.size();
        }
        return ans;
    }
};

// 7 min