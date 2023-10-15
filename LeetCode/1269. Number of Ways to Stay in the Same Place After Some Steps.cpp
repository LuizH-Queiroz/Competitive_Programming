/*
You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left,
1 position to the right in the array, or stay in the same place (The pointer should not be placed outside
the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0
after exactly steps steps. Since the answer may be too large, return it modulo 1e9 + 7.
*/


class Solution {
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps+1, vector<int>(min(arrLen, steps)+1, -1));
        int modulo = 1'000'000'007;

        function<int(int, int)> solve;
        solve = [&](int n, int pos) {
            if (pos == -1 || pos == arrLen)
                return 0;
            else if (dp[n][pos] != -1)
                return dp[n][pos];
            else if (n == 0)
                return dp[n][pos] = (pos == 0);
            
            int ways = solve(n-1, pos);
            ways = (ways + solve(n-1, pos-1)) % modulo;
            ways = (ways + solve(n-1, pos+1)) % modulo;

            return dp[n][pos] = ways;
        };

        dp[0][0] = 1;
        return solve(steps, 0);
    }
};