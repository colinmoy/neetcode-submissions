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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1, *curr2 = list2;
        ListNode* result;
        if (list1 == NULL && list2 == NULL) {
            return NULL;
        } else if (list1 == NULL) {
            return list2;
        } else if (list2 == NULL) {
            return list1;
        } else if (list1->val <= list2->val) {
            result = list1;
            curr1 = curr1->next;
        } else {
            result = list2;
            curr2 = curr2->next;
        }
        ListNode* curr = result;
        while (curr1 != NULL || curr2 != NULL) {
            if (curr1 == NULL) {
                curr->next = curr2;
                curr2 = curr2->next;
            } else if (curr2 == NULL) {
                curr->next = curr1;
                curr1 = curr1->next;
            } else if (curr1->val <= curr2->val) {
                curr->next = curr1;
                curr1 = curr1->next;
            } else {
                curr->next = curr2;
                curr2 = curr2->next;
            }
            curr = curr->next;
        }
        return result;
    }
};
