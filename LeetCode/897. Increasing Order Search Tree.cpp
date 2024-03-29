/*
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree,
and every node has no left child and only one right child.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> nodes;

        function<void(TreeNode*)> inorder;
        inorder = [&](TreeNode *node) {
            if (node == nullptr)
                return;
            
            inorder(node->left);
            nodes.push(node);
            inorder(node->right);
        };


        inorder(root);
        root = nullptr;

        while(!nodes.empty())
        {
            nodes.top()->left = nullptr;
            nodes.top()->right = root;

            root = nodes.top();
            nodes.pop();
        }

        return root;
    }
};