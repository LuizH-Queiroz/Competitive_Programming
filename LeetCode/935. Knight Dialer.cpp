/*
The chess knight has a unique movement, it may move two squares vertically and one square horizontally,
or two squares horizontally and one square vertically (with both forming the shape of an L).
The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:


We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).


Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to
dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 10e9 + 7.
*/


class Solution {
public:

    long long mod = 1'000'000'007;

    int knightDialer(int n) {
        vector<vector<long long>> dp(n+1, vector<long long>(10, -1));
        vector<vector<int>> nextNums = {
            {4, 6}, // 0
            {6, 8}, // 1
            {7, 9}, // 2
            {4, 8}, // 3
            {0, 3, 9}, // 4
            {}, // 5
            {0, 1, 7}, // 6
            {2, 6}, // 7
            {1, 3}, // 8
            {2, 4} // 9
        };

        function<long long(int, int)> solve;
        solve = [&](int moves, int num) {
            if (moves == 0)
                return 1ll;
            else if (dp[moves][num] != -1)
                return dp[moves][num];
            

            long long ans = 0;
            for (int i = 0; i < nextNums[num].size(); i++)
                ans = (ans + solve(moves-1, nextNums[num][i])) % mod;
            
            return dp[moves][num] = ans;
        };


        long long ans = 0;
        for (int i = 0; i <= 9; i++)
            ans = (ans + solve(n-1, i)) % mod;
        
        return ans;
    }
};