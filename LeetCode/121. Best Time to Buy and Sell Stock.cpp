/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int maxPrice = prices.back();

        for (int i = prices.size()-2; i >= 0; i--)
        {
            maxProfit = max(maxProfit, maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }

        return maxProfit;
    }
};