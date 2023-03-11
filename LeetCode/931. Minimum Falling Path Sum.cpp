/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either
directly below or diagonally left/right. Specifically, the next element from position (row, col) will be
(row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minVal;

        for (int i = matrix.size()-2; i >= 0; i--)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                minVal = matrix[i+1][j];

                if (j-1 >= 0)
                    minVal = min(minVal, matrix[i+1][j-1]);
                if (j+1 < matrix[i+1].size())
                    minVal = min(minVal, matrix[i+1][j+1]);
                
                matrix[i][j] += minVal;
            }
        }


        minVal = matrix[0][0];
        for (int i = 1; i < matrix[0].size(); i++)
        {
            minVal = min(minVal, matrix[0][i]);
        }

        return minVal;
    }
};