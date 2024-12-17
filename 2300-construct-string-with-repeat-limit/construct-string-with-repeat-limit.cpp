// POTD Dec'17, 2024
// Dec'17, 2024 06:38 pm

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n=s.size();

        string s1=s, ans;
        unordered_map<char, int>mp;
        sort(s1.begin(), s1.end(), greater<int>());
        cout<<s1<<endl;

        for(auto it:s1)mp[it]++;
        int cnt=1, k=repeatLimit;
        ans+= s1[0];
        mp[s1[0]]--;

        for(int i=1;i<n;i++){
            if(cnt==k || s1[i]!= ans.back()){
                if(s1[i]== ans.back()){
                    for(int j= s1[i]-1; j>='a'; j--){
                        if(mp[j]>0){
                            ans+= (j) ;
                            mp[(j)]--;
                            break;
                        }
                    }

                    if(ans.back()== s1[i]){
                        break;
                    }
                }
                cnt=0;
            }
            if(mp[s1[i]]){
                ans+= s1[i];
                mp[s1[i]]--;
            }
            cnt++;
        }

        return ans;
    }
};