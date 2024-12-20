// POTD Dec'20. 2024
// Dec'20, 2024 01:02 pm

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
    int traverse(TreeNode* root){
        if(!root){
            return 0;
        }

        return max(traverse(root->left), traverse(root->right))+1;
    }

    void form(TreeNode*root, int k, vector<vector<int>>&v){
        if(!root){
            return;
        }

        v[k].push_back(root->val);
        form(root->left, k+1, v);
        form(root->right, k+1, v);
    }
    void reversed(TreeNode*root, int k, vector<vector<int>>&v){
        if(!root){
            return ;
        }

        if(k%2){
            root->val= v[k].back();
            v[k].pop_back();
        }
        reversed(root->left, k+1, v);
        reversed(root->right, k+1, v);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        int n=traverse(root);
        vector<vector<int>>v(n);

        form(root, 0, v);
        for(auto it:v){
            reverse(it.begin(), it.end());
        }

        reversed(root, 0, v);
        return root;
    }
};

// 12 min