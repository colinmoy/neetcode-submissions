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
        int result = root->val;
        dfs(root, result);
        return result;
    }

private:
    int dfs(TreeNode* root, int& result) {
        if (root == NULL) {
            return 0;
        }
        int l = max(dfs(root->left, result), 0);
        int r = max(dfs(root->right, result), 0);
        result = max(result, root->val + l + r);
        return root->val + max(l, r);
    }
};
