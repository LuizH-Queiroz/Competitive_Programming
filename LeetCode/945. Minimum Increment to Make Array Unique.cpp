/*
You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment
nums[i] by 1.

Return the minimum number of moves to make every value in nums unique.

The test cases are generated so that the answer fits in a 32-bit integer.
*/


class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int operations = 0;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i] >= nums[i+1])
            {
                operations += abs(nums[i+1] - nums[i]) + 1;
                nums[i+1] = nums[i]+1;
            }
        }

        return operations;
    }
};