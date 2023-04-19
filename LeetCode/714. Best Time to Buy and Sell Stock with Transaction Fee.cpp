/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int max_profit = 0;
        int max_sell = prices.back();
        int temp;

        for (int i = prices.size()-2; i >= 0; i--)
        {
            temp = max_profit;
            max_profit = max(max_profit, -prices[i] + max_sell - fee);
            max_sell = max(max_sell, prices[i] + temp);
        }

        return max_profit;
    }
};