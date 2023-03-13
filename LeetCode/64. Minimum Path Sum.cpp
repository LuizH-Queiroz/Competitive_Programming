/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int minVal;

        for (int i = grid.size()-1; i >= 0; i--)
        {
            for (int j = grid[i].size()-1; j >= 0; j--)
            {
                if (i+1 < grid.size() && j+1 < grid[i].size())
                    minVal = min(grid[i+1][j], grid[i][j+1]);
                else if (i+1 < grid.size())
                    minVal = grid[i+1][j];
                else if (j+1 < grid[i].size())
                    minVal = grid[i][j+1];
                else
                    minVal = 0;


                grid[i][j] += minVal;
            }
        }

        return grid[0][0];
    }
};