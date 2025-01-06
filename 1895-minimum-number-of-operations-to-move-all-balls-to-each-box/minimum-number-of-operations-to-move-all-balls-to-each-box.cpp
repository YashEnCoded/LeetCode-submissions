// POTD Jan'6, 2024
// Jan'6, 2024 07:10 pm

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n, 0);
        vector<int>pre(n+1, 0);
        vector<int>suf(n+1, 0);
        int cnt=0;

        cnt= boxes[0]-'0';
        for(int i=1;i<n;i++){
            pre[i]= pre[i-1] + cnt;
            cnt+= boxes[i] - '0'; 
        }

        cnt= boxes[n-1] - '0';
        for(int i=n-2;i>=0;i--){
            suf[i]= suf[i+1] + cnt;
            cnt+= boxes[i] - '0';
        }

        for(int i=0;i<n;i++){
            ans[i]= pre[i]+ suf[i];
        }

        return ans;
    }
};

// 3 min
// O(N) soln