/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by
a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i,
meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path
starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> entryDepth(graph.size(), 0);
        vector<int> exitDepth(graph.size(), 0);
        vector<bool> isSafe(graph.size(), true);
        int globalTimer = 0;


        function<bool(int)> dfs;
        dfs = [&](int vertice) {
            entryDepth[vertice] = ++globalTimer;

            for (int outAdjacent : graph[vertice])
            {
                if (entryDepth[outAdjacent] == 0)
                {
                    if (dfs(outAdjacent) == false)
                        isSafe[vertice] = false;
                }
                else if (entryDepth[outAdjacent] <= entryDepth[vertice]
                        && (exitDepth[outAdjacent] == 0 || !isSafe[outAdjacent]))
                {
                    isSafe[vertice] = false;
                }
            }

            exitDepth[vertice] = ++globalTimer;
            return isSafe[vertice];
        };


        vector<int> ans;
        for (int i = 0; i < graph.size(); i++)
        {
            if (entryDepth[i] == 0)
                dfs(i);
            
            if (isSafe[i])
                ans.push_back(i);
        }

        return ans;
    }
};