// Jan'4, 2024 10:00 pm

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size(), m= matrix[0].size();

        int urow=0, lrow=0, lcol=0, rcol=0;
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                lcol=1;
            }
            if(matrix[i][m-1]==0){
                rcol=1;
            }
        }

        for(int j=0; j<m;j++){
            if(matrix[0][j]==0){
                urow=1;
            }
            if(matrix[n-1][j]==0){
                lrow=1;
            }
        }

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                    matrix[n-1][j]=0;
                    matrix[i][m-1]=0;
                }
            }
        }

        for(int i=1;i<n-1;i++){
            if(matrix[i][0]==0 || matrix[i][m-1]==0){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=1;j<m-1;j++){
            if(matrix[0][j]==0 || matrix[n-1][j]==0){
                for(int i=0;i<n; i++){
                    matrix[i][j]=0;
                }
            }
        }

        if(urow){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
        if(lrow){
            for(int j=0;j<m;j++){
                matrix[n-1][j]=0;
            }
        }
        if(lcol){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
        if(rcol){
            for(int i=0;i<n;i++){
                matrix[i][m-1]=0;
            }
        }
    }
};

// 29 min