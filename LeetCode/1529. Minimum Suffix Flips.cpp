/*
You are given a 0-indexed binary string target of length n. You have another binary string s of length n that is initially set to all zeros.
You want to make s equal to target.

In one operation, you can pick an index i where 0 <= i < n and flip all bits in the inclusive range [i, n - 1].
Flip means changing '0' to '1' and '1' to '0'.

Return the minimum number of operations needed to make s equal to target.
*/


class Solution {
public:
    int minFlips(string target) {
        int counter = 0;
        char currentState = '0';

        for (int i = 0; i < target.size(); i++)
        {
            if (target[i] != currentState)
            {
                currentState = target[i];
                counter++;
            }
        }

        return counter;
    }
};