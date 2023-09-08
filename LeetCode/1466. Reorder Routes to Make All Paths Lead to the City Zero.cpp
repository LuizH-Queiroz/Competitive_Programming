/*
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel
between two different cities (this network form a tree). Last year, The ministry of transport decided
to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum
number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.
*/


class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> entryList(n);
        vector<vector<int>> outList(n);
        vector<bool> visited(n, false);
        int counter = 0;

        // Preprocessing
        for (vector<int> connection : connections)
        {
            outList[connection[0]].push_back(connection[1]);
            entryList[connection[1]].push_back(connection[0]);
        }


        function<void(int)> dfs;
        dfs = [&](int vertice) {
            visited[vertice] = true;

            for (int entryAdjacent : entryList[vertice])
            {
                if (!visited[entryAdjacent])
                {
                    dfs(entryAdjacent);
                }
            }

            for (int outAdjacent : outList[vertice])
            {
                if (!visited[outAdjacent])
                {
                    counter++;
                    dfs(outAdjacent);
                }
            }
        };

        dfs(0);
        return counter;
    }
};