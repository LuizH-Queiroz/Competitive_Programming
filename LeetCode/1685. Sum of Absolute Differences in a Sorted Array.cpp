/*
You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that result[i] is equal to the
summation of absolute differences between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).
*/


class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans(nums.size());

        ans[0] = 0;
        for (int i = 1; i < nums.size(); i++)
            ans[0] += nums[i] - nums[0];
        
        int diff;
        for (int i = 1; i < nums.size(); i++)
        {
            diff = nums[i] - nums[i-1];
            ans[i] = ans[i-1] + diff*i - diff*(nums.size() - i);
        }

        return ans;
    }
};