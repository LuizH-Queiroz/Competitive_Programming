/*
A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti],
the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.
*/


class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int cost = 0;
        priority_queue<int, vector<int>, greater<int> > a_to_b;
        priority_queue<int, vector<int>, greater<int> > b_to_a;

        for (int i = 0; i < costs.size(); i++)
        {
            if (costs[i][0] <= costs[i][1])
            {
                cost += costs[i][0];
                a_to_b.push(costs[i][1] - costs[i][0]);
            }
            else
            {
                cost += costs[i][1];
                b_to_a.push(costs[i][0] - costs[i][1]);
            }
        }


        while(a_to_b.size() > costs.size()/2)
        {
            cost += a_to_b.top();
            a_to_b.pop();
        }

        while(b_to_a.size() > costs.size()/2)
        {
            cost += b_to_a.top();
            b_to_a.pop();
        }


        return cost;
    }
};