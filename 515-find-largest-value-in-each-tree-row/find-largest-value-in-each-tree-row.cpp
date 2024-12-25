// Dec'25, 2024 09:14 pm

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
    void solve(int depth, TreeNode* root, vector<int>&ans){
        if(!root){
            return;
        }
        if(ans.size()<depth+1){
            ans.push_back(INT_MIN);
        }
        ans[depth]= max(ans[depth], root->val);
        solve(depth+1, root->left, ans);
        solve(depth+1, root->right, ans);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        solve(0, root, ans);
        return ans;
    }
};

// 3 min