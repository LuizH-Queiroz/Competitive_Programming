/*
Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between
any two consecutive elements is the same.

    For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
    For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.

A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

    For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].

The test cases are generated so that the answer fits in 32-bit integer.
*/


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<map<long long, int>> dp(nums.size()); // dp[{index, diff}] = number of arithmetic subsequences
                                                     // that starts at 'index' and has 'diff' difference
                                                     // (including subsequences of length 2)
        int counter = 0;

        for (int i = nums.size()-1; i >= 0; i--)
        {
            for (int j = nums.size()-1; j > i; j--)
            {
                long long diff = (long long) nums[j] - (long long) nums[i];
                
                dp[i][diff] += 1 + dp[j][diff];
                counter += dp[j][diff];
            }
        }

        return counter;
    }
};