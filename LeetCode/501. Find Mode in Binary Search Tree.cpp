/*
Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most
frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
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
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        map<int, int> counter;

        function<void(TreeNode*)> dfs;
        dfs = [&](TreeNode *node) {
            if (node == nullptr)
                return;
            
            counter[node->val]++;
            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);
        int maxCounter = 0;
        for (auto it = counter.begin(); it != counter.end(); it++)
        {
            if (it->second > maxCounter)
            {
                maxCounter = it->second;

                ans.clear();
                ans.push_back(it->first);
            }
            else if (it->second == maxCounter)
            {
                ans.push_back(it->first);
            }
        }

        return ans;
    }
};