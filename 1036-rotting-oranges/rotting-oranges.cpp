// Dec'25, 2024 07:58 pm

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();

        queue<pair<pair<int, int>, int>>q;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i, j}, 0});
                }
                else if(grid[i][j]==1){
                    vis[i][j]=1;
                }
            }
        }

        int time=0;
        int dir[]= {-1, 0, 1, 0, -1};
        while(!q.empty()){
            int i= q.front().first.first, j= q.front().first.second;
            int curt= q.front().second;
            
            q.pop();
            time= max(time, curt);
            for(int d=0;d<4;d++){
                int x= i + dir[d];
                int y= j + dir[d+1];
                if(min(x,y)>=0 && x<n && y<m && vis[x][y]==1){
                    vis[x][y]=2;
                    q.push({{x, y}, curt+1});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};

// 15 min