// POTD Jan'6, 2024
// Jan'6, 2024 06:45 pm

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i]+= (boxes[j]-'0')*(abs(j-i));
            }
        }

        return ans;
    }
};

// 4 min