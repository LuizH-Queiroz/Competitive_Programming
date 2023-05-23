/*
Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;

        function<void(Node*, int)> traverse;
        traverse = [&](Node *node, int level) {
            if (node == nullptr)
                return;
            
            
            if (level == ans.size())
                ans.push_back(vector<int>());
            
            ans[level].push_back(node->val);
            for (int i = 0; i < node->children.size(); i++)
                traverse(node->children[i], level+1);
        };

        traverse(root, 0);
        return ans;
    }
};