/*
Along a long library corridor, there is a line of seats and decorative plants.
You are given a 0-indexed string corridor of length n consisting of letters 'S' and 'P' where each 'S'
represents a seat and each 'P' represents a plant.

One room divider has already been installed to the left of index 0, and another to the right of index n - 1.
Additional room dividers can be installed. For each position between indices i - 1 and i (1 <= i <= n - 1),
at most one divider can be installed.

Divide the corridor into non-overlapping sections, where each section has exactly two seats with any number
of plants. There may be multiple ways to perform the division. Two ways are different if there is a position
with a room divider installed in the first way but not in the second way.

Return the number of ways to divide the corridor. Since the answer may be very large, return it modulo 10e9 + 7.
If there is no way, return 0.
*/


class Solution {
public:

    long long mod = 1'000'000'007;

    int numberOfWays(string corridor) {
        long long ans = 0;
        int seats = 0;


        for (int i = 0; i < corridor.size(); )
        {
            for (; i < corridor.size() && corridor[i] == 'S'; i++)
            {
                if (seats+1 == 2 && ans == 0)
                    ans = 1;
                seats = max(1, (seats + 1) % 3);
            }

            long long temp = 1;
            for (; i < corridor.size() && corridor[i] == 'P'; i++)
            {
                temp++;
            }

            if (seats == 2 && i != corridor.size())
            {
                ans = (ans * temp) % mod;
                seats = 0;
            }
        }

        if (seats%2 != 0)
            ans = 0;
        return ans;
    }
};