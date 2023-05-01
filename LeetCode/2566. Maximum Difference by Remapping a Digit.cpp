/*
You are given an integer num. You know that Danny Mittal will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

Return the difference between the maximum and minimum values Danny can make by remapping exactly one digit in num.

Notes:

    When Danny remaps a digit d1 to another digit d2, Danny replaces all occurrences of d1 in num with d2.
    Danny can remap a digit to itself, in which case num does not change.
    Danny can remap different digits for obtaining minimum and maximum values respectively.
    The resulting number after remapping can contain leading zeroes.
    We mentioned "Danny Mittal" to congratulate him on being in the top 10 in Weekly Contest 326.

*/


class Solution {
public:
    int minMaxDifference(int num) {
        string strMax = to_string(num);
        char digitMax = '\0';

        string strMin = to_string(num);
        char digitMin = '\0';


        for (int i = 0; i < strMax.size(); i++)
        {
            if (strMax[i] == digitMax)
            {
                strMax[i] = '9';
            }
            else if (strMax[i] != '9' && digitMax == '\0')
            {
                digitMax = strMax[i];
                strMax[i] = '9';
            }

            if (strMin[i] == digitMin)
            {
                strMin[i] = '0';
            }
            else if (strMin[i] != '0' && digitMin == '\0')
            {
                digitMin = strMin[i];
                strMin[i] = '0';
            }
        }

        return (stoi(strMax) - stoi(strMin));
    }
};