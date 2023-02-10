/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes
of the list from position left to position right, and return the reversed list.
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = new ListNode(0, head);
        ListNode* beforeReverseHead = temp;

        // Traverse the list until beforeReverseHead == left-1 (node of index == left-1)
        for (int i = 1; i < left; i++)
        {
            beforeReverseHead = beforeReverseHead->next;
        }

        // Reverse the list
        if (left == 1) head = reverseList(beforeReverseHead->next, right-left);
        else beforeReverseHead->next = reverseList(beforeReverseHead->next, right-left);

        delete temp;
        return head;
    }

    ListNode* reverseList(ListNode* head, int nodesToReverse) {
        ListNode* initialHead = head; // This node will be constantly moving through the list
        ListNode* previousHead = head;

        for(int i = 0; i < nodesToReverse; i++)
        {
            head = initialHead->next;
            initialHead->next = head->next;
            head->next = previousHead;

            previousHead = head; // On next iteration, the current head will be the previous head
        }

        return head;
    }
};