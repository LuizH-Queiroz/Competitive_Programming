/*
Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements
in two non-overlapping subarrays with lengths firstLen and secondLen.

The array with length firstLen could occur before or after the array with length secondLen,
but they have to be non-overlapping.

A subarray is a contiguous part of an array.
*/


class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<int> firstSum(nums.size(), 0);
        vector<int> secondSum(nums.size(), 0);


        function<void(vector<int>&, int)> createSum;
        createSum = [&](vector<int>& vec, int len) {
            for (int i = 0; i < len; i++)
                vec[0] += nums[i];
            
            int lastIndex = nums.size() - len;
            for (int i = 1; i <= lastIndex; i++)
                vec[i] = vec[i-1] - nums[i-1] + nums[i+(len-1)];
        };


        // Assigning values to the suffix sum vectors
        createSum(firstSum, firstLen);
        createSum(secondSum, secondLen);


        // Finding the maximum
        int maximum = 0;
        int firstMax = 0;
        int secondMax = 0;
        int lastIndex = nums.size() - (firstLen + secondLen);

        for (int i = lastIndex; i >= 0; i--)
        {
            firstMax = max(firstMax, firstSum[i+secondLen]);
            secondMax = max(secondMax, secondSum[i+firstLen]);

            maximum = max(maximum, max(firstSum[i] + secondMax, secondSum[i] + firstMax));
        }

        return maximum;
    }
};