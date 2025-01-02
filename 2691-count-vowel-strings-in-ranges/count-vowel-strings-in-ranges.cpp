// POTD Jan'2, 2024
// Jan'2, 2024 06:50 pm

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n= words.size();

        vector<int>v;

        char vowel[]= {'a', 'e', 'i', 'o', 'u'};
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                for(int k=0;k<5;k++){
                    if(words[i][0]== vowel[j] && words[i][words[i].size()-1]== vowel[k]){
                        v.push_back(i);
                        break;
                    }
                }
            }
        }

        vector<int>ans;
        int m= queries.size();
        for(int i=0;i<m;i++){
            auto l= lower_bound(v.begin(), v.end(), queries[i][0]);
            auto r= upper_bound(v.begin(), v.end(), queries[i][1]);
            ans.push_back(r-l);
        }
        return ans;
    }
};

// 10 min