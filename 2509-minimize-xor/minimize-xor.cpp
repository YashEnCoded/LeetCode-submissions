// POTD Jan'15, 2025 
// Jan'15, 2025 10:15 am

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x=0;
        vector<int>bit1 (33, 0), bit2(33, 0);
        int n1= num1, n2= num2, i=0, cnt1=0, mxset=0;

        while(n2){
            cnt1+= n2%2;
            n2/=2;
        }
        while(n1){
            bit1[i++]= n1%2;
            n1/=2;
        }
        reverse(bit1.begin(), bit1.end());

        for(int i=0;i<33;i++){
            if(bit1[i]==1 && cnt1>0){
                bit2[i]=1;
                cnt1--;
                mxset= max(mxset, 33-i);
            }
        }

        if(cnt1>0){
            for(int i=32;i>=0; i--){
                if(cnt1>0 && bit1[i]==0){
                    bit2[i]=1;
                    cnt1--;
                    mxset= max(mxset, 33-i);
                }
            }
        }

        long long cur=0;
        for(int i=0;i<33;i++){
            cur+= bit2[i];
            if(i<32)cur*=2;

        }

        return cur;
    }
};

// 22 min