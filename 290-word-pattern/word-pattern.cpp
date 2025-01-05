// Jan'5, 2024 04:08 pm

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n= pattern.size(), m=s.size();
        map<char, string>mp;
        map<string, char>mp1;

        int j=0;
        for(int i=0;i<n;i++){
            if(j>=m){
                return false;
            }
            string s1;
            s1+= s[j];
            while(j<m && s[j]!=' '){
                s1+= s[j++];
            }
            j++;
            if(mp.find(pattern[i])!= mp.end() && mp[pattern[i]]!=s1){
                return false;
            }
            if(mp1.find(s1)!= mp1.end() && mp1[s1]!=pattern[i]){
                return false;
            }
            // cout<<mp[pattern[i]]<<" "<<s1<<endl;
            mp[pattern[i]]= s1;
            mp1[s1]= pattern[i];
        }
        if(j<m){
            return false;
        }
        return true;
    }
};

// 13 min