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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrder(root, result, 0);
        return result;
    }

private:

    void levelOrder(TreeNode* root, vector<vector<int>>& result, int height) {
        if (root == NULL) {
            return;
        } else if (result.size() <= height) {
            result.push_back({});
        }
        result[height].push_back(root->val);
        levelOrder(root->left, result, height + 1);
        levelOrder(root->right, result, height + 1);
    }
};
