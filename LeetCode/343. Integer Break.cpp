/*
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product
of those integers.

Return the maximum product you can get.
*/


class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        dp[1] = 1;
        dp[2] = 1;

        function<int(int)> solve;
        solve = [&](int val) {
            if (dp[val] != -1)
                return max(val, dp[val]);
            
            for (int i = 1; (val-i) > 0; i++)
            {
                dp[val] = max(dp[val], solve(i) * solve(val-i));
            }

            return max(val, dp[val]);
        };


        solve(n);
        return dp[n];
    }
};