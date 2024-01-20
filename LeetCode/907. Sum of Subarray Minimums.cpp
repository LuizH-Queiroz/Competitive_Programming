/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.

Since the answer may be large, return the answer modulo 10e9 + 7.
*/


class Solution {
public:

    long long MOD = 1'000'000'007;


    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<long long, long long>> minPrev;
        long long currSum = 0;
        long long ans = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            pair<long long, long long> newPair = {arr[i], 1};

            currSum += arr[i];
            while(!minPrev.empty() && minPrev.top().first > arr[i])
            {
                currSum -= (minPrev.top().first - arr[i]) * minPrev.top().second;
                newPair.second += minPrev.top().second;
                minPrev.pop();
            }

            minPrev.push(newPair);
            ans = (ans + currSum) % MOD;
        }

        return ans;
    }
};