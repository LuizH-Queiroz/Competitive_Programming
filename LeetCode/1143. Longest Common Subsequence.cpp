/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing
the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.
*/


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> lcs(text1.size()+1, vector<int>(text2.size()+1, 0));

        for (int i = text1.size()-1; i >= 0; i--)
        {
            for (int j = text2.size()-1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                    lcs[i][j] = 1 + lcs[i+1][j+1];
                else
                    lcs[i][j] = max(lcs[i+1][j], lcs[i][j+1]);
            }
        }

        return lcs[0][0];
    }
};