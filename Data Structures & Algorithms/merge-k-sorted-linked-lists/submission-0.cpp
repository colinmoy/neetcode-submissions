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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0 || lists[0] == NULL) {
            return NULL;
        }
        vector<ListNode*> curr(lists);
        bool cont = false;
        for (ListNode* node : curr) {
            if (node != NULL) {
                cont = true;
                break;
            }
        }
        ListNode* result = NULL;
        bool first = true;
        while (cont) {
            bool finding = true;
            int min, ind;
            ListNode* prev;
            for (unsigned i = 0; i < curr.size(); i++) {
                if (curr[i] != NULL && (finding || curr[i]->val < min)) {
                    min = curr[i]->val;
                    ind = i;
                    finding = false;
                }
            }
            if (first) {
                result = curr[ind];
                first = false;
            } else {
                prev->next = curr[ind];
            }
            prev = curr[ind];
            curr[ind] = curr[ind]->next;
            cont = false;
            for (ListNode* node : curr) {
                if (node != NULL) {
                    cont = true;
                    break;
                }
            }
        }
        return result;
    }
};
