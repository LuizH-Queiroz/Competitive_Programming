/*
Given a binary tree, determine if it is height-balanced.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
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
    bool isBalanced(TreeNode* root) {
        bool balanced = true;

        function<int(TreeNode*)> dfs;
        dfs = [&](TreeNode *node) {
            if (node == nullptr)
                return 0;
            
            int leftDepth = dfs(node->left);
            int rightDepth = dfs(node->right);

            if (abs(leftDepth - rightDepth) > 1)
                balanced = false;
            
            return 1 + max(leftDepth, rightDepth);
        };

        dfs(root);
        return balanced;
    }
};