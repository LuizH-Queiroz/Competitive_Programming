/*
You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).
*/


class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for (int row = 0; row < grid.size(); row++)
        {
            if (grid[row][0] == 0)
                toggleRow(grid, row);
        }

        int zero_counter;
        for (int col = 1; col < grid[0].size(); col++)
        {
            zero_counter = 0;
            for (int row = 0; row < grid.size(); row++)
            {
                if (grid[row][col] == 0)
                    zero_counter++;
            }

            if (zero_counter > grid.size()/2)
                toggleColumn(grid, col);
        }


        int sum = 0;
        int power = 1;
        int aux;
        for (int col = grid[0].size()-1; col >= 0; col--)
        {
            aux = 0;
            for (int row = 0; row < grid.size(); row++)
                aux += grid[row][col];
            
            sum += aux * power;
            power *= 2;
        }

        return sum;
    }


    void toggleRow(vector<vector<int>>& grid, int row) {
        for (int i = 0; i < grid[row].size(); i++)
            grid[row][i] = (grid[row][i] + 1) % 2;
    }

    void toggleColumn(vector<vector<int>>& grid, int column) {
        for (int i = 0; i < grid.size(); i++)
            grid[i][column] = (grid[i][column] + 1) % 2;
    }
};