/*
You are given the head of a linked list.

Remove every node which has a node with a strictly greater value anywhere to the right side of it.

Return the head of the modified linked list.
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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> nodes; // With this stack we can access the nodes backwards
        int greaterValue;

        for (ListNode *node = head; node != nullptr; node = node->next)
        {
            nodes.push(node);
        }


        greaterValue = nodes.top()->val;
        nodes.pop();
        ListNode* toDelete = nullptr;
        while(!nodes.empty())
        {
            // if (nodes.top()->next must be deleted)
            if (toDelete)
            {
                nodes.top()->next = nodes.top()->next->next;
                delete toDelete;
            }

            if (nodes.top()->val < greaterValue) toDelete = nodes.top();
            else toDelete = nullptr;

            greaterValue = max(greaterValue, nodes.top()->val);

            nodes.pop();
        }

        // This node can only be the 'head'
        if (toDelete)
        {
            head = head->next;
            delete toDelete;
        }

        return head;
    }
};