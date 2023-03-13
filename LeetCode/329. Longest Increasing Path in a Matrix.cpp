/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or
move outside the boundary (i.e., wrap-around is not allowed).
*/


class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> longestPath(matrix.size());
        for (int i = 0; i < longestPath.size(); i++)
            longestPath[i] = vector(matrix[i].size(), 0);

        int ans = 0; // answer/solution/return value


        function<int(int, int)> dfs;
        dfs = [&](int i, int j) {
            if (longestPath[i][j] != 0)
                return longestPath[i][j];
            

            int res = 0;
            if (i-1 >= 0 && matrix[i-1][j] > matrix[i][j])
                res = max(res, 1 + dfs(i-1, j));

            if (i+1 < matrix.size() && matrix[i+1][j] > matrix[i][j])
                res = max(res, 1 + dfs(i+1, j));
            
            if (j-1 >= 0 && matrix[i][j-1] > matrix[i][j])
                res = max(res, 1 + dfs(i, j-1));
            
            if (j+1 < matrix[i].size() && matrix[i][j+1] > matrix[i][j])
                res = max(res, 1 + dfs(i, j+1));            
            

            longestPath[i][j] = max(1, res);
            ans = max(ans, longestPath[i][j]);

            return longestPath[i][j];
        };


        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                dfs(i, j);


        return ans;
    }
};