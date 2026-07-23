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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "N,";
        }
        queue<TreeNode*> q;
        string result;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) {
                result += "N,";
            } else {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        if (val == "N") {
            return NULL;
        }
        TreeNode* result = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(result);
        while (getline(ss, val, ',')) {
            TreeNode* node = q.front();
            q.pop();
            if (val != "N") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            getline(ss, val, ',');
            if (val != "N") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return result;
    }
};
