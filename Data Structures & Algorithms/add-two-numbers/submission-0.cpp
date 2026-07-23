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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> x1, x2;
        while (l1 != NULL) {
            x1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            x2.push_back(l2->val);
            l2 = l2->next;
        }
        int carry = 0, ind = 0;
        ListNode* result = NULL, *curr = result;
        while (ind < (int) x1.size() || ind < (int) x2.size()) {
            int sum = carry;
            carry = 0;
            if (ind < (int) x1.size()) {
                sum += x1[ind];
            }
            if (ind < (int) x2.size()) {
                sum += x2[ind];
            }
            carry = sum / 10;
            sum = sum % 10;
            if (result == NULL) {
                result = new ListNode(sum);
                curr = result;
            } else {
                curr->next = new ListNode(sum);
                curr = curr->next;
            }
            ind++;
        }
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }
        return result;
    }
};
