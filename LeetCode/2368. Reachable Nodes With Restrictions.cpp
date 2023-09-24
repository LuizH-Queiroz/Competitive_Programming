/*
There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that
there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted
which represents restricted nodes.

Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.

Note that node 0 will not be a restricted node.
*/


class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adjacencyList(n);
        vector<bool> canVisit(n, true);
        vector<bool> visited(n, false);


        function<int(int)> dfs;
        dfs = [&](int vertice) {
            visited[vertice] = true;
            int counter = 1;

            for (int adjacent : adjacencyList[vertice])
            {
                if (canVisit[adjacent] && !visited[adjacent])
                {
                    counter += dfs(adjacent);
                }
            }

            return counter;
        };


        for (int i = 0; i < restricted.size(); i++)
            canVisit[restricted[i]] = false;
        
        // Creating the Adjacency List
        for (vector<int>& edge : edges)
        {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        return dfs(0);
    }
};