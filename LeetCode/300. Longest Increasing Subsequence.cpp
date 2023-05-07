/*
Given an integer array nums, return the length of the longest strictly increasing
subsequence.
*/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> longest(nums.size(), 1);
        int ans = 1;


        for (int i = nums.size()-1; i >= 0; i--)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                if (nums[j] > nums[i])
                {
                    longest[i] = max(longest[i], longest[j]+1);
                    ans = max(ans, longest[i]);
                }
            }
        }

        return ans;
    }
};