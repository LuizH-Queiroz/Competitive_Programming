/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place
form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
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
    int rob(TreeNode* root) {
        int notRob_max = 0;

        if (root->left)
        {
            rob(root->left);
            notRob_max += root->left->val;

            if (root->left->left)
                root->val += root->left->left->val;
            
            if (root->left->right)
                root->val += root->left->right->val;
        }
        if (root->right)
        {
            rob(root->right);
            notRob_max += root->right->val;

            if (root->right->left)
                root->val += root->right->left->val;
            
            if (root->right->right)
                root->val += root->right->right->val;
        }

        root->val = max(root->val, notRob_max);
        return root->val;
    }
};