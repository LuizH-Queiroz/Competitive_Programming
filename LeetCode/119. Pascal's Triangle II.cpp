/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it
*/


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prevLevel = vector(1, 1);
        vector<int> currLevel = vector(1, 1);

        for (int i = 1; i <= rowIndex; i++)
        {
            currLevel.resize(prevLevel.size()+1);
            currLevel[currLevel.size()-1] = 1;

            for (int j = 1; j < prevLevel.size(); j++)
            {
                currLevel[j] = prevLevel[j] + prevLevel[j-1];
            }

            prevLevel = currLevel;
        }

        return currLevel;
    }
};