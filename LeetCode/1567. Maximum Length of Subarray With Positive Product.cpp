/*
Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.
*/


class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int negProd_maxLen = 0; // Maximum length of last calculated negative product subarray
        int posProd_maxLen = 0; // Maximum length of last calculated positive product subarray
        int ans = 0;

        for (int i = nums.size()-1; i >= 0; i--)
        {
            if (nums[i] == 0)
            {
                negProd_maxLen = 0;
                posProd_maxLen = 0;
            }
            else if (nums[i] < 0)
            {
                int temp = negProd_maxLen;
                negProd_maxLen = posProd_maxLen + 1;

                if (temp > 0)
                    posProd_maxLen = temp + 1;
                else
                    posProd_maxLen = 0;
            }
            else // nums[i] > 0
            {
                if (negProd_maxLen > 0)
                    negProd_maxLen += 1;

                posProd_maxLen += 1;
            }

            ans = max(ans, posProd_maxLen);
        }

        return ans;
    }
};