/*
Given the following details of a matrix with n columns and 2 rows :

    The matrix is a binary matrix, which means each element in the matrix can be 0 or 1.
    The sum of elements of the 0-th(upper) row is given as upper.
    The sum of elements of the 1-st(lower) row is given as lower.
    The sum of elements in the i-th column(0-indexed) is colsum[i], where colsum is given as an integer array with length n.

Your task is to reconstruct the matrix with upper, lower and colsum.

Return it as a 2-D integer array.

If there are more than one valid solution, any of them will be accepted.

If no valid solution exists, return an empty 2-D array.
*/


class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> matrix(2, vector<int>(colsum.size(), 0));

        for (int i = 0; i < colsum.size(); i++)
        {
            if (colsum[i] == 2)
            {
                matrix[0][i] = matrix[1][i] = 1;
                upper--;
                lower--;
            }
            else if (colsum[i] == 1)
            {
                if (upper > lower)
                {
                    matrix[0][i] = 1;
                    upper--;
                }
                else
                {
                    matrix[1][i] = 1;
                    lower--;
                }
            }

            if (upper < 0 || lower < 0)
                return vector<vector<int>>();
        }

        if (upper > 0 || lower > 0)
            return vector<vector<int>>();
        else
            return matrix;
    }
};