/*
There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting
of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0.
You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional
road connecting cities ai and bi.

There is a meeting for the representatives of each city. The meeting is in the capital city.

There is a car in each city. You are given an integer seats that indicates the number of seats in each car.

A representative can use the car in their city to travel or change the car and ride with another
representative. The cost of traveling between two cities is one liter of fuel.

Return the minimum number of liters of fuel to reach the capital city.
*/


class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> adjacencyList(roads.size()+1);
        vector<bool> visited(roads.size()+1, false);
        long long minCost = 0;

        for (vector<int> road : roads)
        {
            adjacencyList[road[0]].push_back(road[1]);
            adjacencyList[road[1]].push_back(road[0]);
        }

        function<int(int)> dfs;
        dfs = [&](int vertice) {
            visited[vertice] = true;
            int representativesCounter = 1;

            for (int adjacent : adjacencyList[vertice])
            {
                if (!visited[adjacent])
                    representativesCounter += dfs(adjacent);
            }

            if (vertice != 0)
            {
                minCost += representativesCounter / seats;
                if (representativesCounter % seats > 0)
                    minCost += 1;
            }
            
            return representativesCounter;
        };


        dfs(0);
        return minCost;
    }
};