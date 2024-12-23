// POTD Dec'23, 2024
//Dec'23, 2024 07:06 pm

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root, vector<vector<int>>&v, int k){

        if(!root){
            return;
        }
        if(v.size()!=k+1){
            vector<int> temp;
            v.push_back(temp);
        }
        v[k].push_back(root->val);

        solve(root->left, v, k+1);
        solve(root->right, v, k+1);
    }
public:
    int minimumOperations(TreeNode* root) {
        vector<vector<int>>v;

        solve(root, v, 0);
        int ans=0;
        for(auto it:v)ans+=it.size();
        cout<<ans<<endl;
        ans=0;

        for(auto it:v){
            int n= it.size();
            map<int, int>mp;
            vector<int>cur= it;
            sort(cur.begin(), cur.end());

            for(int i=0;i<n;i++){
                mp[cur[i]]=i;
            }
            int ansi=0;
            for(int i=0; i<n;){
                int ind= mp[it[i]]; 
                if(i!=ind){
                    ansi++;
                    // swap(it[i], it[ind]);
                    int temp= it[i];
                    it[i]= it[ind];
                    it[ind]= temp; 
                }
                else {
                    i++;
                }

            }
            ans+=ansi;
        }
        return ans;
    }
};

// 38 min
// Comments