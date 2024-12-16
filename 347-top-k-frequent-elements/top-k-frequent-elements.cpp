// Dec'16, 2024 07:47 pm

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int, int>> pq;
        map<int, int>mp;

        vector<int> ans;
        for(auto it:nums){
            mp[it]++;
        }

        for(auto it:mp){
            pq.push({it.second, it.first});
        }

        int cnt=0;
        while(cnt<k){
            auto it= pq.top();
            int cur= it.second;
            ans.push_back(cur);

            pq.pop();
            cnt++;
        }

        return ans;
    }
};

// 3 min