/*
You are given a string s, which contains stars *.

In one operation, you can:

    Choose a star in s.
    Remove the closest non-star character to its left, as well as remove the star itself.

Return the string after all stars have been removed.

Note:

    The input will be generated such that the operation is always possible.
    It can be shown that the resulting string will always be unique.
*/


class Solution {
public:
    string removeStars(string s) {
        int stars = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '*')
                s[i-(stars*2)] = s[i];
            else
                stars++;
        }

        s.erase(s.end()-(stars*2), s.end());
        return s;
    }
};