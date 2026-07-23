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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (isAncestor(root->left, p) && isAncestor(root->left, q)) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (isAncestor(root->right, p) && isAncestor(root->right, q)) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }

private:
    bool isAncestor(TreeNode* root, TreeNode* p) {
        if (p == NULL) {
            return true;
        } else if (root == NULL) {
            return false;
        } else {
            return root->val == p->val || isAncestor(root->left, p) || isAncestor(root->right, p);
        }
    }
};
