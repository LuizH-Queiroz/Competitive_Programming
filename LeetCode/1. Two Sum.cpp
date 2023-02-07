/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> indexOf; // indexOf[val] = index
        vector<int> solution;

        // indexOf[nums[0]] = 0; -- This won't work in the 'if' statement
        // because the value 0 is considered false, so we need to check it using
        // a separate condition, via operator||
        for (int i = 1; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if (indexOf[complement] || complement == nums[0])
            {
                solution.push_back(i);
                solution.push_back(indexOf[complement]); // When indexOf[val] does not exist, then
                                                         // indexOf[val] == 0

                break;
            }
            indexOf[nums[i]] = i;
        }

        return solution;
    }
};