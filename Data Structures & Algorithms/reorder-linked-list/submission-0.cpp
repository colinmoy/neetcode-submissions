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
        vector<ListNode*> xs;
        while (head != NULL) {
            xs.push_back(head);
            head = head->next;
        }
        unsigned l = 0, r = xs.size() - 1;
        for (unsigned i = 0; i < xs.size(); i++) {
            if (i < xs.size() - 1) {
                if (i % 2 == 0) {
                    xs[l]->next = xs[r];
                    l++;
                } else {
                    xs[r]->next = xs[l];
                    r--;
                }
            } else {
                if (i % 2 == 0) {
                    xs[l]->next = NULL;
                } else {
                    xs[r]->next = NULL;
                }
            }
        }
    }
};
