/*
A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.
*/


class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> toZero(s.size(), 0);
        vector<int> toOne(s.size(), 0);
        int minFlips = s.size();

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                toZero[i]++;
            if (i-1 >= 0)
                toZero[i] += toZero[i-1];
        }

        for (int i = s.size()-1; i >= 0; i--)
        {
            if (s[i] == '0')
                toOne[i]++;
            if (i+1 < s.size())
                toOne[i] += toOne[i+1];
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (i-1 >= 0)
                minFlips = min(minFlips, toZero[i-1] + toOne[i]);
            else
                minFlips = min(minFlips, toOne[i]);
            
            if (i+1 < s.size())
                minFlips = min(minFlips, toZero[i] + toOne[i+1]);
            else
                minFlips = min(minFlips, toZero[i]);
        }

        return minFlips;
    }
};