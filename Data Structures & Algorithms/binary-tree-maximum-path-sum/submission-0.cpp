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
public:
    int maxPathSum(TreeNode* root) {
        int res = -1e7;
        solve(root, res);
        return res;
    }
    int solve(TreeNode* root, int& res){
        if(!root) return 0;

        int lh = max(0, solve(root->left, res));
        int rh = max(0, solve(root->right, res));

        int temp = root->val + max(lh, rh);
        res = max(res, root->val +lh + rh);
        return temp;
    }
};
