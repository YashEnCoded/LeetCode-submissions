// Dec'24, 2024 10:53 pm

class Solution {
public:
    int uniquePaths(int m, int n) {
        int mx= max(m, n)-1, mn=1, l= (n+m-2);

        long long ans= 1;
        while(l>mx){
            ans*=l;
            ans/=mn;
            l--;
            mn++;
        }
        return ans;
    }
};

// 10 min