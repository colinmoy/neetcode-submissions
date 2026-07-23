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
    int goodNodes(TreeNode* root) {
        int result = 0;
        queue<int> maxes;
        queue<TreeNode*> nodes;
        maxes.push(root->val);
        nodes.push(root);
        while (!nodes.empty()) {
            int m = maxes.front();
            maxes.pop();
            TreeNode* node = nodes.front();
            nodes.pop();
            if (node->val >= m) {
                result++;
            }
            m = max(m, node->val);
            if (node->left != NULL) {
                maxes.push(m);
                nodes.push(node->left);
            }
            if (node->right != NULL) {
                maxes.push(m);
                nodes.push(node->right);
            }
        }
        return result;
    }
};
