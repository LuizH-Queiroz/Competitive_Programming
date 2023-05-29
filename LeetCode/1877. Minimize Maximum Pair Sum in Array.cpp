/*
The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.

    For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.

Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:

    Each element of nums is in exactly one pair, and
    The maximum pair sum is minimized.

Return the minimized maximum pair sum after optimally pairing up the elements.
*/


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans;

        sort(nums.begin(), nums.end());

        ans = nums[0] + nums.back();
        for (int i = 1; i < nums.size()/2; i++)
            ans = max(ans, nums[i] + nums[(nums.size() - (i+1))]);
        
        return ans;
    }
};