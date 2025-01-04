//Jan'4, 2024 09:26 pm

class Solution {
    int solve(int i, int j, vector<vector<int>>&triangle){
        int n= triangle.size();
        if(j>i){
            return 1e9;
        }
        if(i==n-1){
            return triangle[i][j];
        }

        int same= triangle[i][j] + solve(i+1, j, triangle);
        int next= triangle[i][j] + solve(i+1, j+1, triangle);

        return min(same,next);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();

        // return solve(0, 0, triangle);

        vector<int>suf(n+1, 1e9), cur(n+1, 1e9);
        for(int j=0;j<n;j++){
            suf[j]= triangle[n-1][j];
        }
        cur= suf;
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int same= triangle[i][j] + suf[j];
                int next= triangle[i][j] + suf[j+1];

                cur[j]= min(same,next);
            }
            suf= cur;
        } 
        return cur[0];
    }
};

// 13 min