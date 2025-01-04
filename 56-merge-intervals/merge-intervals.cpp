// Jan'4, 2024 11:36 pm

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n= intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        int l= intervals[0][0], r= intervals[0][1];

        for(int i=1;i<n;i++){
            if(r>= intervals[i][0]){
                r= max(intervals[i][1], r);
            }
            else {
                ans.push_back({l,r});
                l= intervals[i][0], r= intervals[i][1];
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};

// 5 min