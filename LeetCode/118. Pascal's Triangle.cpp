/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it
*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows); // Initialize with 'numRows' size
        pascal[0] = vector(1, 1); // numRows >= 1

        for (int i = 1 /* Start loop at second level */; i < numRows; i++)
        {
            vector<int> newLevel(i+1); // Initialize with size 'i+1'
            newLevel[0] = 1; // First value = 1
            newLevel[i] = 1; // Last value = 1

            // The loop must not go through the values 0 and i, as they
            // are the first and last indexes and already have a value (1)
            for (int j = 1; j < i; j++)
            {
                // Remember that 'i' is also tracking at which level we are, such that:
                // current level = i
                // previous level == i-1
                newLevel[j] = pascal[i-1][j] + pascal[i-1][j-1];
            }

            pascal[i] = newLevel;
        }

        return pascal;
    }
};