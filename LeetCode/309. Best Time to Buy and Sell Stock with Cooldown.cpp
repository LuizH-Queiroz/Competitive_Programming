/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like
(i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> max_profit(prices.size(), 0);
        int maxSell = prices.back();

        for (int i = max_profit.size()-2; i >= 0; i--)
        {
            max_profit[i] = max(max_profit[i+1], -prices[i] + maxSell);

            if ((i+2) < max_profit.size())
                maxSell = max(maxSell, prices[i] + max_profit[i+2]);
            else
                maxSell = max(maxSell, prices[i]);
        }

        return max_profit[0];
    }
};