/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land)
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid
are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
*/


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int currentArea;
        int maxArea = 0;


        function<bool(int, int)> isLand;
        isLand = [&](int i, int j) {
            return ((i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()) && (grid[i][j] == 1));
        };

        function<void(int, int)> dfs;
        dfs = [&](int i, int j) {
            grid[i][j] = 0;
            currentArea++;

            if (isLand(i-1, j))
                dfs(i-1, j);

            if (isLand(i, j+1))
                dfs(i, j+1);
            
            if (isLand(i+1, j))
                dfs(i+1, j);
            
            if (isLand(i, j-1))
                dfs(i, j-1);
        };


        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (isLand(i, j))
                {
                    currentArea = 0;
                    dfs(i, j);
                    maxArea = max(maxArea, currentArea);
                }
            }
        }

        return maxArea;
    }
};