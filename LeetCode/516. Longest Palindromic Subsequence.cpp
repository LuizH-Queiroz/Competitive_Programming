/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing
the order of the remaining elements.
*/


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> lps(s.size()+1, vector<int>(s.size()+1, 0));

        for (int i = s.size()-1; i >= 0; i--)
        {
            for (int j = s.size()-1; j >= 0; j--)
            {
                if (s[i] == s[s.size() - (1 + j)])
                    lps[i][j] = 1 + lps[i+1][j+1];
                else
                    lps[i][j] = max(lps[i+1][j], lps[i][j+1]);
            }
        }

        return lps[0][0];
    }
};