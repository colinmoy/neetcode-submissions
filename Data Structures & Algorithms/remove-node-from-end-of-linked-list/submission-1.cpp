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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int len = 0;
        while (curr != NULL) {
            len++;
            curr = curr->next;
        }
        ListNode* prev = NULL;
        curr = head;
        if (len - n == 0) {
            return head->next;
        }
        while (len - n > 0) {
            prev = curr;
            curr = curr->next;
            len--;
        }
        if (prev == NULL) {
            return NULL;
        }
        prev->next = curr->next;
        return head;
    }
};
