/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can
rob tonight without alerting the police.
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        struct stateVal {
            int rob;
            int notRob;
        };
        vector<struct stateVal> maxMoney(nums.size());
        maxMoney.back().rob = nums.back();
        maxMoney.back().notRob = 0;


        for (int i = maxMoney.size()-2; i >= 0; i--)
        {
            maxMoney[i].rob = nums[i];
            if ((i+2) < nums.size())
                maxMoney[i].rob += max(maxMoney[i+2].rob, maxMoney[i+2].notRob);
            
            maxMoney[i].notRob = max(maxMoney[i+1].rob, maxMoney[i+1].notRob);
        }

        return max(maxMoney[0].rob, maxMoney[0].notRob);
    }
};