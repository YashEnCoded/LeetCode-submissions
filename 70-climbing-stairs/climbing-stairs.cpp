// Dec'23, 2024 11:16 pm

class Solution {
public:
    int climbStairs(int n) {
        if(n<3)return n;
        int cur=0, pre=2, prepre= 1;
        while(n>2){
            cur= pre+ prepre;
            prepre= pre;
            pre= cur;
            n--;
        }
        return cur;
    }
};

// 2 min