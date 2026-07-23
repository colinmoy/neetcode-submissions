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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return vector<int>();
        }
        queue<int> heights;
        queue<TreeNode*> nodes;
        heights.push(1);
        nodes.push(root);
        vector<int> result;
        while (!nodes.empty()) {
            int h = heights.front();
            heights.pop();
            TreeNode* node = nodes.front();
            nodes.pop();
            if (h > result.size()) {
                result.push_back(node->val);
            } else {
                result[h - 1] = node->val;
            }
            if (node->left != NULL) {
                heights.push(h + 1);
                nodes.push(node->left);
            }
            if (node->right != NULL) {
                heights.push(h + 1);
                nodes.push(node->right);
            }
        }
        return result;
    }
};
