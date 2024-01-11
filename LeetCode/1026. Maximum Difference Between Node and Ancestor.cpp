/*
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where
v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.
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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;


        function<void(TreeNode*, pair<int, int>)> solve;
        solve = [&](TreeNode *node, pair<int, int> minmax) {
            if (node == nullptr)
                return;
            
            ans = max(ans, abs(node->val - minmax.first));
            ans = max(ans, abs(node->val - minmax.second));

            minmax.first = min(minmax.first, node->val);
            minmax.second = max(minmax.second, node->val);

            solve(node->left, minmax);
            solve(node->right, minmax);
        };


        solve(root, {root->val, root->val});
        return ans;
    }
};