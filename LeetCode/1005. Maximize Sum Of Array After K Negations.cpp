/*
Given an integer array nums and an integer k, modify the array in the following way:

    choose an index i and replace nums[i] with -nums[i].

You should apply this process exactly k times. You may choose the same index i multiple times.

Return the largest possible sum of the array after modifying it in this way.
*/


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int sum = 0;
        int minAbs = abs(nums[0]);

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0 & k > 0)
            {
                nums[i] = -nums[i];
                k--;
            }
            sum += nums[i];
            minAbs = min(minAbs, abs(nums[i]));
        }

        if (k % 2 != 0)
            sum -= 2*minAbs;
        
        return sum;
    }
};