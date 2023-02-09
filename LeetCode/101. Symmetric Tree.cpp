/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
    // Recursive approach
    bool isSymmetric(TreeNode* root) {
        return symmetric(root->left, root->right);
    }

    bool symmetric(TreeNode* leftNode, TreeNode* rightNode) {
        if (!leftNode && !rightNode) return true;
        else if (!leftNode || !rightNode) return false;
        else if (leftNode->val != rightNode->val) return false;


        return (symmetric(leftNode->left, rightNode->right)
            && symmetric(leftNode->right, rightNode->left));
    }


    // Iterative approach
    /*
    bool isSymmetric(TreeNode* root) {
        TreeNode *leftNode, *rightNode;
        queue<TreeNode*> q;

        q.push(root->left);
        q.push(root->right);

        while(!q.empty())
        {
            leftNode = q.front();
            q.pop();
            rightNode = q.front();
            q.pop();

            if (!leftNode && !rightNode) continue;
            else if (!leftNode || !rightNode) return false;
            else if (leftNode->val != rightNode->val) return false;

            q.push(leftNode->left);
            q.push(rightNode->right);

            q.push(leftNode->right);
            q.push(rightNode->left);
        }

        return true;
    }
    */
};