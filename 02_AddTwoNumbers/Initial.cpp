/**
 * 34% - runtime and memory
 */

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
        
        ListNode *initial = nullptr;
        ListNode *curr = nullptr;
        int carry = 0;
        int sum = 0;

        while (true) {
            sum = 0;
            if (l1 == nullptr && l2 == nullptr) {                
                if (carry == 1) {
                    curr->next = new ListNode();
                    curr = curr->next;
                    curr->val = carry;
                }
                return initial;
            }

            if (curr == nullptr) {
                initial = new ListNode();
                curr = initial;
            }
            else {
                curr->next = new ListNode();
                curr = curr->next;
            }
            
            if (l1 == nullptr && l2 != nullptr) {
                sum = l2->val;
                l2 = l2->next;
            }
            else if (l1 != nullptr && l2 == nullptr) {
                sum = l1->val;
                l1 = l1->next;
            }
            else {
                sum = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            curr->val = ((sum % 10) + carry) % 10;
            carry = sum + carry >= 10 ? 1 : 0;
        }

        return initial;
    }
};