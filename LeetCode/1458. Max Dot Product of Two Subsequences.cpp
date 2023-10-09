/*
Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none)
of the characters without disturbing the relative positions of the remaining characters.
(ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).
*/


class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));

        for (int i = dp.size()-1; i >= 0; i--)
        {
            for (int j = dp[i].size()-1; j >= 0; j--)
            {
                dp[i][j] = nums1[i] * nums2[j];

                if ((i+1) < dp.size())
                {
                    dp[i][j] = max(dp[i][j], dp[i+1][j]);
                }
                if ((j+1) < dp[i].size())
                {
                    dp[i][j] = max(dp[i][j], dp[i][j+1]);
                }
                if ((i+1) < dp.size() && (j+1) < dp[i].size())
                {
                    dp[i][j] = max(dp[i][j], max(dp[i+1][j+1], nums1[i] * nums2[j] + dp[i+1][j+1]));
                }
            }
        }

        return dp[0][0];
    }
};