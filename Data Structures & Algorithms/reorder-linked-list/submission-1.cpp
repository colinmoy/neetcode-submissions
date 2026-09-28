/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        int len = 1;
        ListNode* curr = head;
        queue<ListNode*> q;
        stack<ListNode*> s;
        while (curr->next) {
            curr = curr->next;
            len++;
            q.push(curr);
            s.push(curr);
        }
        curr = head;
        for (int i = 0; i < len - 1; i++) {
            if (i % 2 == 0) {
                curr->next = s.top();
                s.pop();
            } else {
                curr->next = q.front();
                q.pop();
            }
            curr = curr->next;
        }
        curr->next = NULL;
    }
};
