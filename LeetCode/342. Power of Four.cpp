/*
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.
*/


class Solution {
public:
    bool isPowerOfFour(int n) {
        long long aux = n;
        return (((aux&(-aux)) == aux) && ((aux&(0b01010101010101010101010101010101)) != 0));
    }
};