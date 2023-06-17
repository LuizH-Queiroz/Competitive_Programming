/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

    For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
*/


class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = sqrt(x);
        int middle;

        int val = 0;
        int diff = x;

        int tempDiff;
        while(left <= right)
        {
            middle = (left + right)/2;
            tempDiff = (x - middle*middle);

            if (tempDiff < 0)
            {
                right = middle - 1;
            }
            else
            {
                val = middle;
                diff = tempDiff;
                left = middle + 1;
            }
        }

        return val;
    }
};