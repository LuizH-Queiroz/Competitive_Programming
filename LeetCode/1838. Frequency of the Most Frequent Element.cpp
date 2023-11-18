/*
The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums
and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.
*/


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        map<int, int> valFreq;

        for (int i = 0; i < nums.size(); i++)
            valFreq[nums[i]]++;
        

        int maxFreq = 0;
        int currCost = 0;
        int prevVal = valFreq.begin()->first;
        queue<int> vals;

        for (auto it = valFreq.begin(); it != valFreq.end(); it++)
        {
            int currVal = it->first;
            int currFreq = it->second;

            currCost += (currVal - prevVal) * vals.size();
            while(currCost > k)
            {
                currCost -= currVal - vals.front();
                vals.pop();
            }

            maxFreq = max(maxFreq, currFreq + (int) vals.size());

            for (int i = 0; i < currFreq; i++)
                vals.push(currVal);
            prevVal = currVal;
        }

        return maxFreq;
    }
};