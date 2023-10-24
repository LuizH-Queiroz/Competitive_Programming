/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> sol;


        function<void(TreeNode*, int)> dfs;
        dfs = [&](TreeNode *node, int row) {
            if (node == nullptr)
                return;
            
            if (row == sol.size())
                sol.push_back(INT32_MIN);
            
            sol[row] = max(sol[row], node->val);
            dfs(node->left, row+1);
            dfs(node->right, row+1);
        };


        dfs(root, 0);
        return sol;
    }
};