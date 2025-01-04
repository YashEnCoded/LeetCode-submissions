// Jan'4, 2024 2025 11:47 pm

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n= intervals.size(), ans=0;

        sort(intervals.begin(), intervals.end());
        int l= intervals[0][0], r= intervals[0][1];
        // for(auto it:intervals){
        //     cout<<"["<<it[0]<<", "<<it[1]<<"], ";
        // }
        // cout<<endl;
        // cout<<"l= "<<l<<" r= "<<r<<endl;
        for(int i=1;i<n;i++){
            if(r> intervals[i][0]){
                // cout<<r<<" "<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
                r= min(r, intervals[i][1]);
                ans++;
            }
            else {
                r= intervals[i][1];
            }
        }
        return ans;
    }
};

// 10 min