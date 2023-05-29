/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);

        ans[0] = startingPosition(nums, target);
        ans[1] = endingPosition(nums, target);

        return ans;
    }


    int startingPosition(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int middle;
        int index = -1;

        while(start <= end)
        {
            middle = (start + end)/2;

            if (target < nums[middle])
            {
                end = middle - 1;
            }
            else if (target > nums[middle])
            {
                start = middle + 1;
            }
            else
            {
                index = middle;
                end = middle - 1;
            }
        }

        return index;
    }


    int endingPosition(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int middle;
        int index = -1;

        while(start <= end)
        {
            middle = (start + end)/2;

            if (target < nums[middle])
            {
                end = middle - 1;
            }
            else if (target > nums[middle])
            {
                start = middle + 1;
            }
            else
            {
                index = middle;
                start = middle + 1;
            }
        }

        return index;        
    }
};