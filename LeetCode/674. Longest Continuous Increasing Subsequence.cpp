/*
Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray)
The subsequence must be strictly increasing.

A continuous increasing subsequence is defined by two indices l and r (l < r) such that
it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].
*/


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int longest = 1;
        int current = 1;

        for (int i = nums.size()-2; i >= 0; i--)
        {
            if (nums[i] < nums[i+1])
            {
                current++;
                longest = max(longest, current);
            }
            else
                current = 1;
        }

        return longest;
    }
};