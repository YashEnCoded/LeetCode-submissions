// Dec'24, 2024 01:49 pm
// Striver

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        
        vector<int> pre(amount+1, 0), cur(amount+1, 0);
        // ans= solve(n-1, amount, coins, dp);

        // return ans>=1e9 ? -1: ans;
        
        for(int t=0; t<=amount; t++){
            if(t%coins[0]== 0){
                pre[t]= t/coins[0];
            }
            else {
                pre[t]= 1e9;
            }
        }

        for(int i=1;i<n;i++){
            for(int t=0;t<=amount; t++){        
                int notTake= 0 + pre[t];
                int take=1e9;
                if(coins[i]<= t)take= 1 + cur[t- coins[i]];
                cur[t]= min(take, notTake);
            }
            pre= cur;
        }

        int ans= pre[amount];
        return ans>= 1e9 ? -1 : ans;
    }
};

// 01:30 hour
// Striver



    // int solve(vector<int>&coins, int amount, int& ans, int cur, int i, vector<vector<int>>&dp ){
    //     if(i<0){
    //         return amount==0 ? 0 : (-1e5);
    //     }
    //     // if(!amount){
    //     //     ans= min(ans, cur);
    //     //     return ;
    //     // }

    //     int nottake= solve(coins, amount, ans, cur, i-1, dp);

    //     int k=coins[i];
    //     int take= INT_MAX;
    //     if(k<amount){
    //         take= min(solve(coins, amount-k, ans, cur+1, i, dp)+ 1 , take);
    //     }

    //     return min(take, nottake);
    // }

    // int solve(int i, int amount, vector<int>&coins, vector<vector<int>>& dp){
    //     if(i==0){
    //         if(amount%coins[i] == 0){
    //             return (amount/coins[i]);
    //         }
    //         else return 1e9;
    //     }

    //     if(dp[i][amount]!=-1){
    //         return dp[i][amount];
    //     }

    //     int notTake= 0 + solve(i-1, amount, coins, dp);
    //     int take=1e9;
    //     if(coins[i]<= amount)take= 1 + solve(i, amount- coins[i], coins, dp);

    //     return dp[i][amount]= min(take, notTake);
    // }