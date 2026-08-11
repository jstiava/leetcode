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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *first = l1;
        ListNode *second = l2;
        bool carry = false;

        ListNode *start = nullptr;
        ListNode *curr = nullptr;

        while (first || second)
        {

            int firstValue = first ? first->val : 0;
            int secondValue = second ? second->val : 0;

            int localResult = firstValue + secondValue + (carry ? 1 : 0);
            carry = localResult >= 10;
            localResult = localResult >= 10 ? localResult - 10 : localResult;

            if (start == nullptr)
            {
                start = new ListNode(localResult);
                curr = start;
            }
            else
            {
                ListNode *newNode = new ListNode(localResult);
                curr->next = newNode;
                curr = newNode;
            }

            first = first ? first->next : nullptr;
            second = second ? second->next : nullptr;
        }

        if (carry)
        {
            ListNode *newNode = new ListNode(1);
            curr->next = newNode;
        }

        return start;
    }
};