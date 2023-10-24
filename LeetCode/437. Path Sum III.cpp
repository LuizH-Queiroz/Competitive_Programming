/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the
values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards
(i.e., traveling only from parent nodes to child nodes).
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
    int pathSum(TreeNode* root, int targetSum) {
        map<long long, int> prefix;
        int counter = 0;


        function<void(TreeNode*, long long)> dfs;
        dfs = [&](TreeNode *node, long long currSum) {
            if (node == nullptr)
                return;
            
            currSum += node->val;
            counter += prefix[(currSum - targetSum)];

            prefix[currSum]++;
            dfs(node->left, currSum);
            dfs(node->right, currSum);
            prefix[currSum]--;
        };


        prefix[0] = 1;
        dfs(root, 0);
        return counter;
    }
};