/*
Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

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
    vector<int> preorder(Node* root) {
        vector<int> ans;

        function<void(Node*)> traverse;
        traverse = [&](Node *node) {
            if (node == nullptr)
                return;
            
            ans.push_back(node->val);
            for (int i = 0; i < node->children.size(); i++)
                traverse(node->children[i]);
        };

        traverse(root);
        return ans;
    }
};