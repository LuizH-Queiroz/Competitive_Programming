/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.
*/


class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size())
            return 0;
        
        vector<vector<unsigned int>> dp(s.size()+1, vector<unsigned int>(t.size()+1, 0));
        for (int i = 0; i < dp.size(); i++)
            dp[i].back() = 1;

        for (int i = dp.size()-2; i >= 0; i--)
        {
            for (int j = dp[i].size()-2; j >= 0; j--)
            {
                dp[i][j] = dp[i+1][j];
                if (s[i] == t[j])
                    dp[i][j] += dp[i+1][j+1];
            }
        }

        return dp[0][0];
    }
};