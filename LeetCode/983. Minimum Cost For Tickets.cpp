/*
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days.
Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

    a 1-day pass is sold for costs[0] dollars,
    a 7-day pass is sold for costs[1] dollars, and
    a 30-day pass is sold for costs[2] dollars.

The passes allow that many days of consecutive travel.

    For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.
*/


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> minCost(days.size());
        minCost.back() = *min_element(costs.begin(), costs.end());

        for (int i = days.size()-2; i >= 0; i--)
        {
            minCost[i] = costs[0] + minCost[i+1];
            
            bool weekPass = false;
            bool monthPass = false;
            for (int j = i+1; j < days.size(); j++)
            {
                if (!weekPass && days[j]-days[i] >= 7)
                {
                    minCost[i] = min(minCost[i], costs[1] + minCost[j]);
                    weekPass = true;
                }
                if (!monthPass && days[j]-days[i] >= 30)
                {
                    minCost[i] = min(minCost[i], costs[2] + minCost[j]);
                    monthPass = true;
                }

                if (weekPass && monthPass)
                    break;
            }

            if (!weekPass)
                minCost[i] = min(minCost[i], costs[1]);
            if (!monthPass)
                minCost[i] = min(minCost[i], costs[2]);
        }

        return minCost[0];
    }
};