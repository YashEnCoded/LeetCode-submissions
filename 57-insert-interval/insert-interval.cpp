// Jan'4, 2024 11:24 pm

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int n=intervals.size();

        int l= intervals[0][0], r= intervals[0][1];
        for(int i=1;i<n;i++){
            if(r>=intervals[i][0]){
                r= max(r, intervals[i][1]);
            }
            else {
                ans.push_back({l,r});
                l= intervals[i][0], r= intervals[i][1];
            }
        }
        ans.push_back({l,r});
        return ans;
    }
};

// 6 min