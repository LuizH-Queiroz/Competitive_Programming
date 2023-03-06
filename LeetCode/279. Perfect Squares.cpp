/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words,
it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
*/


class Solution {
public:
    int numSquares(int n) {
        vector<int> minSquares(n+1, n); // minSquares.size() = n+1
                                        // 0 <= i <= n, minSquares[i] = n
        minSquares[0] = 0;

        for (int num = 1; num <= n; num++)
        {
            for (int sq = 1; num-sq*sq >= 0; sq++)
            {
                minSquares[num] = min(minSquares[num], minSquares[num-sq*sq] + 1);
            }
        }

        return minSquares[n];
    }
};