// Dec'19, 2024 09:41 pm

class Solution {
public:
    int magicalString(int n) {
        string s="122";
        int k=0, pre=2;

        while(k<=n){
            if(s[pre]=='2'){
                char c=s.back();
                if(c=='1'){
                    s+="22";
                }
                else {
                    s+="11";
                }
                k+=2;
            }
            else {
                char c=s.back();
                if(c=='1'){
                    s+="2";
                }
                else {
                    s+="1";
                }
                k+=1;
            }
            pre++;
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnt++;
        }
        return cnt;
    }
};

// 18 min