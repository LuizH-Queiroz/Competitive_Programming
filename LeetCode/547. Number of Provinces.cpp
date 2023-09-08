/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with
city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are
directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int provinces = 0;


        function<void(int)> dfs;
        dfs = [&](int vertice) {
            visited[vertice] = true;

            for (int i = 0; i < isConnected[vertice].size(); i++)
            {
                if (isConnected[vertice][i] && !visited[i])
                    dfs(i);
            }
        };


        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!visited[i])
            {
                provinces++;
                dfs(i);
            }
        }

        return provinces;
    }
};