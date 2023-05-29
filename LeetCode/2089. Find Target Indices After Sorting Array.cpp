/*
You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order.
If there are no target indices, return an empty list. The returned list must be sorted in increasing order.
*/


class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lowerCount = 0;
        int targetCount = 0;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < target)
                lowerCount++;
            else if (nums[i] == target)
                targetCount++;
        }

        ans.resize(targetCount);
        for (int i = 0; i < targetCount; i++)
            ans[i] = lowerCount + i;
        
        return ans;
    }
};