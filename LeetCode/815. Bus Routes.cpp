/*
You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus
repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the
sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially),
and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target.
Return -1 if it is not possible.
*/


class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        vector<vector<int>> busStops(routes.size()); // busStops[i] is a vector which contains the positions where
                                                     // the bus i stop
        vector<vector<int>> stopBuses(1'000'000);    // stopBuses[i] is a vector which contains the buses that stop
                                                     // on bus stop i
        

        for (int i = 0; i < routes.size(); i++)
        {
            for (int j = 0; j < routes[i].size(); j++)
            {
                busStops[i].push_back(routes[i][j]);
                stopBuses[routes[i][j]].push_back(i);
            }
        }

        /************ BFS ************/
        queue<pair<int, int>> q; // Will store bus stops
        vector<bool> visitedStop(1'000'000, false);
        vector<bool> visitedBus(routes.size(), false);

        q.push({source, 0});
        visitedStop[source] = true;

        while(!q.empty())
        {
            int currStop = q.front().first;
            int currCost = q.front().second;
            q.pop();

            if (currStop == target)
                return currCost;

            for (int bus : stopBuses[currStop])
            {
                if (!visitedBus[bus])
                {
                    for (int stop : busStops[bus])
                    {
                        if (!visitedStop[stop])
                        {
                            q.push({stop, currCost + 1});
                            visitedStop[stop] = true;
                        }
                    }

                    visitedBus[bus] = true;
                }
            }
        }

        return -1;
    }
};