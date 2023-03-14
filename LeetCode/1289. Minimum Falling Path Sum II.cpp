/*
Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that
no two elements chosen in adjacent rows are in the same column.
*/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int gridSize = grid.size();
        if (gridSize == 1)
            return grid[0][0];
        
        vector<int> lowestNum(2, 0); // Initialize with both values 0
                                     // --> lowestNum = [0, 0]
        for (int i = gridSize-1; i >= 0; i--)
        {
            vector<int> next_lowestNum;
            for (int j = gridSize-1; j >= 0; j--)
            {
                // Add to the current position the minimum path until now
                if ((i+1 < gridSize) && (grid[i+1][j] != lowestNum[0]))
                    grid[i][j] += lowestNum[0];
                else
                    grid[i][j] += lowestNum[1];

                // Insert new value and pop the greater if we have more than 2
                next_lowestNum.push_back(grid[i][j]);
                if (next_lowestNum.size() > 2)
                {
                    sort(next_lowestNum.begin(), next_lowestNum.end());
                    next_lowestNum.pop_back();
                }
            }

            lowestNum = next_lowestNum;
        }

        return lowestNum[0];
    }
};