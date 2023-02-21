/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row,
you may move to either index i or index i + 1 on the next row.
*/

/*
Link to my solution description at LeetCode:
https://leetcode.com/problems/triangle/solutions/3215330/linear-10-lines-of-code-approach-c/
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size()-2; i >= 0; i--)
        {
            for (int j = triangle[i].size()-1; j >= 0; j--)
            {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }

        return triangle[0][0];
    }
};