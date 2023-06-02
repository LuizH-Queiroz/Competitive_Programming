/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.
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
    void reorderList(ListNode* head) {
        deque<ListNode*> nodes;
        ListNode *aux = nullptr;

        for (aux = head; aux != nullptr; aux = aux->next)
            nodes.push_back(aux);
        
        aux = head;
        while(!nodes.empty())
        {
            aux->next = nodes.front();
            aux = aux->next;
            nodes.pop_front();

            if (!nodes.empty())
            {
                aux->next = nodes.back();
                aux = aux->next;
                nodes.pop_back();
            }
        }
        aux->next = nullptr;
    }
};