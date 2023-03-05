/*
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        int middle, targetIndex = 0;

        while(start <= end)
        {
            middle = (start + end)/2;

            if (nums[middle] < target)
            {
                targetIndex = start = middle + 1;
            }
            else if (nums[middle] > target)
            {
                targetIndex = middle;
                end = middle - 1;
            }
            else
            {
                targetIndex = middle;
                break;
            }
        }

        return targetIndex;
    }
};