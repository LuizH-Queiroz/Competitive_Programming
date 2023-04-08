/*
You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

    If x is a negative integer, then abs(x) = -x.
    If x is a non-negative integer, then abs(x) = x.

*/


class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currentMax = 0, currentMin = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            currentMax += nums[i];
            if (currentMax < 0)
                currentMax = 0;
            
            currentMin += nums[i];
            if (currentMin > 0)
                currentMin = 0;


            ans = max(ans, max(currentMax, -currentMin));
        }

        return ans;
    }
};