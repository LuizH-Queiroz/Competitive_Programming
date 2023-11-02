/*
Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average
of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
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
    int averageOfSubtree(TreeNode* root) {
        int counter = 0;

        function<pair<int, int>(TreeNode*)> dfs;
        dfs = [&](TreeNode *node) {
            if (node == nullptr)
                return make_pair(0, 0);
            
            pair<int, int> left = dfs(node->left);
            pair<int, int> right = dfs(node->right);
            
            int sum = node->val + left.first + right.first;
            int numNodes = 1 + left.second + right.second;
            if (node->val == sum/numNodes)
                counter++;
            
            return make_pair(sum, numNodes);
        };


        dfs(root);
        return counter;
    }
};