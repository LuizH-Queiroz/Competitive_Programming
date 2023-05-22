/*
Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or vice-versa.
In other words s2 can break s1 or vice-versa.

A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.
*/


class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        bool s1_flag = false;
        bool s2_flag = false;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] > s2[i])
            {
                s1_flag = true;
                if (s2_flag == true)
                    return false;
            }
            else if (s2[i] > s1[i])
            {
                s2_flag = true;
                if (s1_flag == true)
                    return false;
            }
        }

        return true;
    }
};