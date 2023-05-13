/*
You are given an n x n integer matrix. You can do the following operation any number of times:

    Choose any two adjacent elements of matrix and multiply each of them by -1.

Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements.
Return the maximum sum of the matrix's elements using the operation mentioned above.
*/


class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negatives = 0;
        bool hasZero = false;
        int minAbs = abs(matrix[0][0]);

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                    hasZero = true;
                if (matrix[i][j] < 0)
                    negatives++;

                minAbs = min(minAbs, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }

        if ((!hasZero) && (negatives % 2 != 0))
            sum -= 2*minAbs;
        
        return sum;
    }
};