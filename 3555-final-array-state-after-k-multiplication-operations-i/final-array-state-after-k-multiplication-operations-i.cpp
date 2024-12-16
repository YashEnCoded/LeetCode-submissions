//POTD Dec'16, 2024
// Dec'16, 2024 04:16 pm

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n= nums.size();

        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            pq.push({nums[i], i });
        }

        while(k--){
            auto it= pq.top();
            pq.pop();
            int val= it.first;
            int pos= it.second;

            val*=multiplier;
            pq.push({val, pos});
        }

        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();

            int val= it.first;
            int pos= it.second;

            v[pos]= val;
        }
        return v;
    }
};

// 5 min