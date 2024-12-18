// POTD Dec'18, 2024
//Dec'19, 2024 00:54 pm

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n= prices.size();

        vector<int>ans= prices;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(prices[j]<=prices[i]){
                    ans[i]-=prices[j];
                    break;
                }
            }
        }

        return ans;
    }
};

// 3 min