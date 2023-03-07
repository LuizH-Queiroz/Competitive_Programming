/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is
the number of 1's in the binary representation of i.
*/


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        int prevPowerOf2 = 1; // pow(2, 0) == 1

        for (int i = 1; i <= n; i++)
        {
            if (i == 2*prevPowerOf2) prevPowerOf2 = i;
            ans[i] = ans[i-prevPowerOf2] + 1; // ans[prevPowerOf2] == 1
        }

        return ans;
    }

    // Here's a code easier to understand, but doing exactly what the above one does.
    // Let's say the code above is the upgrade of this one
    /*
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        int prevPowerOf2 = 1; // pow(2, 0) == 1

        for (int i = 1; i <= n; i++)
        {
            if (isOdd(i))
            {
                ans[i] = ans[i-1] + 1;
            }
            else if (i == 2*prevPowerOf2)
            {
                ans[i] = 1;
                prevPowerOf2 = i;
            }
            else
            {
                ans[i] = ans[prevPowerOf2] + ans[i-prevPowerOf2];
            }
        }

        return ans;
    }

    bool isOdd(int num) {
        return (num & 1);
    }
    */
};