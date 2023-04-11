/*
The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.
*/


class Solution {
public:
    int maxPower(string s) {
        int currentLength = 1;
        int power = 1;

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i-1])
                currentLength = 1;
            else
                currentLength++;

            power = max(power, currentLength);
        }

        return power;
    }
};