/*
Given an integer array nums, your goal is to make all elements in nums equal.


To complete one operation, follow these steps:

Find the largest value in nums. Let its index be i (0-indexed) and its value be largest.
If there are multiple elements with the largest value, pick the smallest i.

Find the next largest value in nums strictly smaller than largest. Let its value be nextLargest.

Reduce nums[i] to nextLargest.


Return the number of operations to make all elements in nums equal.
*/


class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        vector<int> freq(50'000+1, 0);
        int operations = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        int level = 0;
        for (int i = 1; i < freq.size(); i++)
        {
            if (freq[i] > 0)
            {
                operations += freq[i] * level;
                level++;
            }
        }

        return operations;
    }
};