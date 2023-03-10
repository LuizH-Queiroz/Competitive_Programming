/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element
in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/


class Solution {
public:
    bool canJump(vector<int>& nums) {
        // From now on, we'll change every single value in 'nums' to 1 or 0, meaning:
        //
        // for 0 <= i < nums.size()-1:
        // if (nums[i+nums[i]] == 1) --> on the interval [i+1, i+nums[i]] there is at least 1 way of getting
        //                               to the last index
        // else                      --> it doesn't matter if you jump to any index on the range [i+1, i+nums[i]],
        //                               you simply cannot reach the last index
        //
        // Remember that nums[i] is the maximum jump length from index 'i'
        nums.back() = 1;

        for (int i = nums.size()-2; i >= 0; i--)
        {
            // 'index' is the higher index we can go from 'i'
            int index = min(i+nums[i], (int) nums.size()-1); // Use min() function to make sure we don't go
                                                             // out of bounds

            // if we can reach the last index from here, change all 'nums[j], j >= i && nums[j] == 0' to 1,
            // for if from an index 'k' (k < i) we're able to reach an index such that 'i < index', we certainly
            // can reach 'i', from where we can reach the last index
            // Note: remember that if we already iterated through nums[i] and nums[i] == 1, then we can reach
            // the last index from nums[i]
            if (nums[index] == 1)
            {
                nums[i] = 1;
                for (int j = i+1; j < nums.size() && nums[j] == 0; j++)
                    nums[j] = 1;
            }
            else // It's not possible to reach the last index from here
                nums[i] = 0;
        }

        return nums[0];
    }
};