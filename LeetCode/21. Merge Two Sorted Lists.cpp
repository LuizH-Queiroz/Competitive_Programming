/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode(); // This node won't be part of the new list
        ListNode* mergedList = temp;

        while(list1 && list2)
        {
            if (list1->val < list2->val)
            {
                mergedList->next = list1;
                list1 = list1->next;
            }
            else
            {
                mergedList->next = list2;
                list2 = list2->next;
            }

            mergedList = mergedList->next;
        }

        if (list1) mergedList->next = list1;
        else if (list2) mergedList->next = list2;

        mergedList = temp->next;
        delete temp;
        return mergedList;
    }
};