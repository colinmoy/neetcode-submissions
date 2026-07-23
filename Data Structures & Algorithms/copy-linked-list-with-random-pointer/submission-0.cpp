/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        vector<Node*> nodes;
        unordered_map<Node*, Node*> map;
        while (head != NULL) {
            nodes.push_back(head);
            map[head] = new Node(head->val);
            head = head->next;
        }
        for (Node* node : nodes) {
            map[node]->next = map[node->next];
            map[node]->random = map[node->random];
        }
        return map[nodes[0]];
    }
};
