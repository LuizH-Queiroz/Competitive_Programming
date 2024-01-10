/*
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts
from the node with value start.

Each minute, a node becomes infected if:

    The node is currently uninfected.
    The node is adjacent to an infected node.

Return the number of minutes needed for the entire tree to be infected.
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
    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;


        function<pair<int, int>(TreeNode*)> solve;
        solve = [&](TreeNode *node) {
            if (node == nullptr)
                return make_pair(0, -1);
            
            pair<int, int> left = solve(node->left);
            pair<int, int> right = solve(node->right);

            if (right.second != -1)
                swap(left, right);

            if (node->val == start)
            {
                ans = max(ans, max(left.first, right.first));
                return make_pair(1 + max(left.first, right.first), 1);
            }
            else if (left.second != -1)
            {
                ans = max(ans, left.second + right.first);
                return make_pair(1 + right.first, left.second + 1);
            }
            else
            {
                return make_pair(1 + max(left.first, right.first), -1);
            }
        };


        solve(root);
        return ans;
    }
};