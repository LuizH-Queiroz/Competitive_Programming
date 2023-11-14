/*
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters
(can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
*/


class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstAppear('z'+1, -1);
        vector<int> lastAppear('z'+1, -1);
        vector<bool> used('z'+1);
        int counter = 0;

        for (int i = 0.; i < s.size(); i++)
        {
            if (firstAppear[s[i]] == -1)
                firstAppear[s[i]] = i;
            
            lastAppear[s[i]] = i;
        }

        for (char c = 'a'; c <= 'z'; c++)
        {
            fill(used.begin(), used.end(), false);
            for (int i = firstAppear[c]+1; i <= lastAppear[c]-1; i++)
            {
                if (!used[s[i]])
                {
                    counter++;
                    used[s[i]] = true;
                }
            }
        }

        return counter;
    }
};