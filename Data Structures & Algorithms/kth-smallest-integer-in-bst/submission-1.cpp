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
    int kthSmallest(TreeNode* root, int k) {
        int pos = 1 + numNodes(root->left);
        TreeNode* node = root;
        while (pos != k) {
            if (pos > k) {
                node = node->left;
                pos -= 1 + numNodes(node->right);
            } else {
                node = node->right;
                pos += 1 + numNodes(node->left);
            }
        }
        return node->val;
    }

private:
    int numNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + numNodes(root->left) + numNodes(root->right);
    }
};
