/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths
from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from
node i (i.e., there is a directed edge from node i to node graph[i][j]).
*/


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<vector<int>> paths;
        vector<int> currentPath;
        int target = graph.size()-1;

        function<void(int)> dfs;
        dfs = [&](int node) {
            currentPath.push_back(node);
            if (node == target)
            {
                paths.push_back(currentPath);
                currentPath.pop_back();
                return;
            }
            ///////////////////////////////

            visited[node] = true;

            for (int adjacent : graph[node])
            {
                if (!visited[adjacent])
                    dfs(adjacent);
            }

            currentPath.pop_back();
            visited[node] = false;
        };

        dfs(0);
        return paths;
    }
};