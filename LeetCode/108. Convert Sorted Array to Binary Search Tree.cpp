/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        function<TreeNode* (int, int)> dfs;
        dfs = [&] (int start, int end) -> TreeNode* {
            if (end < start)
                return nullptr;
            
            TreeNode *newNode = new TreeNode;

            int middle = (start + end)/2;
            newNode->val = nums[middle];

            newNode->left = dfs(start, middle-1);
            newNode->right = dfs(middle+1, end);

            return newNode;
        };


        return dfs(0, nums.size()-1);
    }
};