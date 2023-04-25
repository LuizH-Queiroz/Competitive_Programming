/*
Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it into some number of substrings such that:

    Each substring is balanced.

Return the maximum number of balanced strings you can obtain.
*/


class Solution {
public:
    int balancedStringSplit(string s) {
        int counter = 0;
        int L = 0, R = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
                L++;
            else
                R++;
            
            if (L == R)
                counter++;
        }

        return counter;
    }
};