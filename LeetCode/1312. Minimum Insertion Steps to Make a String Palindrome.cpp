/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
*/


class Solution {
public:
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));

        function<int(int, int)> minInsert;
        minInsert = [&](int left, int right) {
            if (left >= right)
                return 0;
            else if (dp[left][right] != -1)
                return dp[left][right];
            
            if (s[left] == s[right])
                return (dp[left][right] = minInsert(left+1, right-1));
            else
                return (dp[left][right] = 1 + min(minInsert(left+1, right), minInsert(left, right-1)));
        };

        return minInsert(0, s.size()-1);
    }
};