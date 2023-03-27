/*
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSubarray;
        int minSubarray;
        int ans;

        ans = maxSubarray = minSubarray = nums.back();
        for (int i = nums.size()-2; i >= 0; i--)
        {
            if (nums[i] == 0)
            {
                maxSubarray = 0;
                minSubarray = 0;
            }
            else if (nums[i] < 0)
            {
                int temp = maxSubarray;
                maxSubarray = max(nums[i], nums[i] * minSubarray);
                minSubarray = min(nums[i], nums[i] * temp);
            }
            else // nums[i] > 0
            {
                maxSubarray = max(nums[i], nums[i] * maxSubarray);
                minSubarray = min(nums[i], nums[i] * minSubarray);
            }

            ans = max(ans, maxSubarray);
        }

        return ans;
    }
};