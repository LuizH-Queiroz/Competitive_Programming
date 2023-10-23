/*
You are given an array of integers nums (0-indexed) and an integer k.

The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1).
A good subarray is a subarray where i <= k <= j.

Return the maximum possible score of a good subarray.
*/


class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i, j;
        int minVal = nums[k];
        int ans = 0;


        function<bool(int)> valid;
        valid = [&](int pos) {
            return (pos >= 0 && pos < nums.size());
        };


        i = j = k;
        while((i > 0) || (j < nums.size()-1))
        {
            while(valid(i-1) && nums[i-1] >= minVal)
                i--;

            while(valid(j+1) && nums[j+1] >= minVal)
                j++;
            

            ans = max(ans, minVal * ((j - i) + 1));

            if (valid(i-1) && valid(j+1))
            {
                if (nums[i-1] >= nums[j+1])
                {
                    i--;
                    minVal = nums[i];
                }
                else
                {
                    j++;
                    minVal = nums[j];
                }
            }
            else if (valid(i-1))
            {
                i--;
                minVal = nums[i];
            }
            else if (valid(j+1))
            {
                j++;
                minVal = nums[j];
            }
        }
        ans = max(ans, minVal * ((j - i) + 1));

        return ans;
    }
};