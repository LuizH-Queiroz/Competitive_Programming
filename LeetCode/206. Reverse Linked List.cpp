/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;

        // head is not nullptr
        ListNode* initialHead = head; // This node will be constantly moving through the list
        ListNode* previousHead = head;

        while(initialHead->next)
        {
            head = initialHead->next;
            initialHead->next = head->next;
            head->next = previousHead;

            previousHead = head; // On next iteration, the current head will be the previous head
        }

        return head;
    }
};