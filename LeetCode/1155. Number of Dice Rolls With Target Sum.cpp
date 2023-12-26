/*
You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll
the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it
modulo 10e9 + 7.
*/


class Solution {
public:
    
    long long mod = 1'000'000'007;
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(target+1, vector<long long>(n+1, -1));
        
        
        function<long long(int, int)> solve;
        solve = [&](int numDice, int currTarget) {
            if (numDice == 0)
                return (currTarget == 0 ? 1ll : 0ll);
            else if (dp[currTarget][numDice] != -1)
                return dp[currTarget][numDice];
            
            
            dp[currTarget][numDice] = 0;
            for (int face = 1; face <= k && currTarget-face >= 0; face++)
            {
                dp[currTarget][numDice] = (dp[currTarget][numDice] + solve(numDice-1, currTarget-face)) % mod;
            }
            
            return dp[currTarget][numDice];
        };
        
        
        return solve(n, target);
    }
};