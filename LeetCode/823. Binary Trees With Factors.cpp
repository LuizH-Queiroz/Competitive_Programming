/*
Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times.
Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 10e9 + 7.
*/


class Solution {
public:

    long long mod = 1'000'000'007;

    int numFactoredBinaryTrees(vector<int>& arr) {
        map<long long, long long> dp;

        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            dp[arr[i]] = 1;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            long long sq = sqrt(arr[i]);
            for (int j = 0; j < arr.size() && arr[j] <= sq; j++)
            {
                if (arr[i]%arr[j] == 0)
                {
                    if (arr[j] == sq && sq*sq == arr[i])
                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[(arr[i]/arr[j])]) % mod;
                    else
                        dp[arr[i]] = (dp[arr[i]] + 2 * dp[arr[j]] * dp[(arr[i]/arr[j])]) % mod;
                }
            }
        }
        
        
        // Counting Solutions
        long long sol = 0;
        for (auto it = dp.begin(); it != dp.end(); it++)
            sol = (sol + (*it).second) % mod;
        
        return sol;
    }
};