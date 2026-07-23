/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        unordered_map<Node*, Node*> map;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            if (map.find(n) == map.end()) {
                map[n] = new Node(n->val);
                for (Node* nbr : n->neighbors) {
                    q.push(nbr);
                }
            }
        }
        q.push(node);
        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            if (map[n]->neighbors.empty()) {
                for (Node* nbr : n->neighbors) {
                    map[n]->neighbors.push_back(map[nbr]);
                    q.push(nbr);
                }
            }
        }
        return map[node];
    }
};
