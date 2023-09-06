/*
You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1.
You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an
undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices,
and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.
*/


class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyList(n);
        vector<int> visited(n, false);
        int components = 0;

        int visitedCounter;
        int degreeSum;

        // Preprocessing
        for (vector<int> edge : edges)
        {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        // DFS function
        function<void(int)> dfs;
        dfs = [&](int vertice) {
            visited[vertice] = true;
            visitedCounter++;
            degreeSum += adjacencyList[vertice].size();

            for (int adjacent : adjacencyList[vertice])
            {
                if (!visited[adjacent])
                    dfs(adjacent);
            }
        };


        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                visitedCounter = 0;
                degreeSum = 0;

                dfs(i);
                if (degreeSum/2 == ((visitedCounter*(visitedCounter-1))/2))
                    components++;
            }
        }

        return components;
    }
};