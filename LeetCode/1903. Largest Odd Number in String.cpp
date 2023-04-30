/*
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a
non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.
*/


class Solution {
public:
    string largestOddNumber(string num) {

        for (int i = num.size()-1; i >= 0; i--)
        {
            if (isEven(num[i]))
                num.pop_back();
            else
                break;
        }

        return num;
    }

    bool isEven(char digit) {
        char even[] = "02468";

        for (int i = 0; i < 5; i++)
            if (digit == even[i])
                return true;
        
        return false;
    }
};