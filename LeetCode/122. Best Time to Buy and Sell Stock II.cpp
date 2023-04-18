/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time.
However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> max_profit(prices.size());
        int max_sell = prices.back();
        max_profit.back() = 0;


        for (int i = prices.size()-2; i >= 0; i--)
        {
            max_profit[i] = max(max_profit[i+1], -prices[i] + max_sell);
            max_sell = max(max_sell, prices[i] + max_profit[i+1]);
        }


        return max_profit[0];
    }
};