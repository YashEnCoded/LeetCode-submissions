// Dec'23, 2024 08:44 pm

class Solution {
public:
    int hammingWeight(int n) {
        return n==0? 0: n%2+ hammingWeight(n/2);
    }
};