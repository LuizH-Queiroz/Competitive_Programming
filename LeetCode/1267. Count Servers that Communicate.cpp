/*
You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that
cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the
same row or on the same column.

Return the number of servers that communicate with any other server.
*/


class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> row(grid.size(), 0), col(grid[0].size(), 0);
        int counter = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    row[i]++;
                    col[j]++;
                    counter++;
                }
            }
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1 && row[i] == 1 && col[j] == 1)
                    counter--;
            }
        }

        return counter;
    }
};