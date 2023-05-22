/*
Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;

        function<void(Node*)> traverse;
        traverse = [&](Node *node) {
            if (node == nullptr)
                return;
            
            for (int i = 0; i < node->children.size(); i++)
                traverse(node->children[i]);

            ans.push_back(node->val);
        };

        traverse(root);
        return ans;
    }
};