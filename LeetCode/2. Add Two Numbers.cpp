/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
        ListNode* temp = new ListNode(); // This node won't be part of the new list
        ListNode* newList = temp;
        int extra = 0;

        while(l1 || l2)
        {
            newList->next = new ListNode();
            newList = newList->next;

            if (l1)
            {
                newList->val += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                newList->val += l2->val;
                l2 = l2->next;
            }
            newList->val += extra;

            if (newList->val >= 10)
            {
                extra = 1;
                newList->val -= 10;
            }
            else extra = 0;
        }

        if (extra) // extra == 1
        {
            newList->next = new ListNode(1 /* extra = 1 */);
        }


        newList = temp->next;
        delete temp;
        return newList;
    }
};