// Dec'24, 2024 04:00 pm

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size(), m= text2.size();

        vector<int>pre(m+1, 0), cur(m+1, 0);

        // if(text1[0]== text2[0]){
        //     pre[0]=1, cur[0]=1;
        // }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int notTake= 0 + max(pre[j+1], cur[j]);
                int take= 0;
                if(text1[i]== text2[j]){
                    if(j!=0)take= 1 + pre[j];
                    else take = 1;
                }

                cur[j+1]= max(take, notTake);
            }
            pre= cur;
        }
        
        int ans=cur[m];
        return ans;
    }
};

// 27 min
// Striver



    // int solve(int i, int j, string text1, string text2){
    //     if(i==0){
    //         if(j<0 || (j==0 && text1[i]== text2[j])){
    //             return 1;
    //         }
    //         else {
    //             return 0;
    //         }
    //     }

    //     int notTake= 0 + solve(i-1, j, text1, text2);
    //     int take= 0;
    //     if(text1[i]== text2[j]){
    //         take= 1 + solve(i-1, j-1, text1, text2);
    //     }

    //     return max(take, notTake);
    // }