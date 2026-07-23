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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        TreeNode* result = new TreeNode(preorder[0]);
        int ind = 0;
        while (inorder[ind] != preorder[0]) {
            ind++;
        }
        vector<int> preleft(ind), preright(preorder.size() - ind - 1), inleft(ind), inright(inorder.size() - ind - 1);
        copy(preorder.begin() + 1, preorder.begin() + ind + 1, preleft.begin());
        copy(preorder.begin() + ind + 1, preorder.end(), preright.begin());
        copy(inorder.begin(), inorder.begin() + ind, inleft.begin());
        copy(inorder.begin() + ind + 1, inorder.end(), inright.begin());
        result->left = buildTree(preleft, inleft);
        result->right = buildTree(preright, inright);
        return result;
    }
};
