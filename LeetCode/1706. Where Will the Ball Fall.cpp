/*
You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the
top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to
the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and
is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is
represented in the grid as -1.
We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of
the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects
the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom
after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.
*/


class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int notCalculated = grid[0].size();
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), notCalculated));
        

        function<bool(int, int, int)> isValid;
        isValid = [&](int i, int j, int val) {
            return ((i >= 0 && i < grid.size()) && (j >= 0 && j < grid[i].size()) && (grid[i][j] == val));
        };


        function<int(int, int)> find;
        find = [&](int i, int j) {
            if (i == grid.size())
                return j;
            else if (dp[i][j] != notCalculated)
                return dp[i][j];

            
            if (isValid(i, j + grid[i][j], grid[i][j]))
                return dp[i][j] = find(i+1, j + grid[i][j]);

            
            return dp[i][j] = -1;
        };


        vector<int> ans(grid[0].size());
        for (int i = 0; i < ans.size(); i++)
            ans[i] = find(0, i);
        
        return ans;
    }
};