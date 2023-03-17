/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums.back();

        for (int i = nums.size()-2; i >= 0; i--)
        {
            nums[i] = max(nums[i], nums[i]+nums[i+1]);
            ans = max(ans, nums[i]);
        }

        return ans;
    }
};