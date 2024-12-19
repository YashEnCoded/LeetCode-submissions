// POTD Dec'19, 2024
//Dec'19, 2024 01:36 pm

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int, int>> v;

        for(int i=0;i<n;i++){
            int l= min(arr[i], i);
            int r= max(arr[i], i);

            v.push_back({l,r});
            // cout<<l<<" "<<r<<endl;
        }
        sort(v.begin(), v.end());

        // for(auto it:v)cout<<it.first<<" "<<it.second<<endl;
        vector<pair<int, int>>ans;
        int l= v[0].first, r=v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first> r){
                ans.push_back({l, r});
                l=v[i].first;
            }
            r= max(r, v[i].second);

            // if(!ans.empty())cout<< ans.back().first<<" "<<ans.back().second<<endl;
        }
        ans.push_back({l,r});

        return ans.size();
    }
};

// 9 min