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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (root->left != NULL && root->val <= root->left->val) {
            return false;
        }
        if (root->right != NULL && root->val >= root->right->val) {
            return false;
        }
        return isValidBST(root->left) && isValidBST(root->right) && lessThan(root->left, root->val) && greaterThan(root->right, root->val);
    }

private:
    bool greaterThan(TreeNode* root, int x) {
        if (root == NULL) {
            return true;
        } else if (root->val <= x) {
            return false;
        }
        return greaterThan(root->left, x) && greaterThan(root->right, x);
    }

    bool lessThan(TreeNode* root, int x) {
        if (root == NULL) {
            return true;
        } else if (root->val >= x) {
            return false;
        }
        return lessThan(root->left, x) && lessThan(root->right, x);
    }
};
