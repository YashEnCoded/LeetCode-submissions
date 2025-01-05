// POTD Jan'5, 2024
// Jan'6, 2024 02:37 am

class Solution {
    vector<int> init(vector<int>&a){
        int n= a.size();

        vector<int>d(n+1, 0);
        d[0]=0, d[n]=0;

        for(int i=1;i<n; i++){
            d[i] = a[i]- a[i-1];
        }

        return d;
    }
    void incr(vector<int>&a, int l, int r, int k){

        a[l]+= k;
        a[r+1]-=k;
    }
    void resolve(vector<int>&a, vector<int>&d){
        int n= a.size();
        a[0]= d[0];
        for(int i=1;i<n;i++){
            a[i]= d[i]+a[i-1];
        }
    }
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n= s.size();
        vector<int>a(n, 0);

        vector<int>d= init(a);
        for(auto it: shifts){
            int k= (it[2]==1 ? 1 : -1);
            incr(d, it[0], it[1], k);
        }

        resolve(a, d);
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;

        for(int i=0;i<n;i++){
            int k= a[i]%26;
            char c= s[i];
            if(k>0){
                if(c+k >'z'){
                    k-= ('z'-c);
                    c= 'a'+k-1;
                }
                else {
                    c+=k;
                }
            }
            else {
                if(c+k<'a'){
                    k+= (c-'a');
                    c= 'z'+k+1;
                }
                else {
                    c+=k;
                }

            }
            s[i]=c;
        }

        return s;
    }
};

// 27 min