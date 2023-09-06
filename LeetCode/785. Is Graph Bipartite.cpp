/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1.
You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to.
More formally, for each v in graph[u], there is an undirected edge between node u and node v.
The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path
between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that
every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
*/


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        bool bipartite = true;

        function<void(int, int)> dfs;
        dfs = [&](int node, int parent) {
            for (int adjacent : graph[node])
            {
                if (adjacent != parent)
                {
                    if (color[adjacent] == -1)
                    {
                        color[adjacent] = 1 - color[node];
                        dfs(adjacent, node);
                    }
                    else if (color[adjacent] == color[node])
                    {
                        bipartite = false;
                    }
                }
            }
        };


        for (int i = 0; i < graph.size(); i++)
        {
            if (color[i] == -1)
            {
                color[i] = 0;
                dfs(i, i);
                if (!bipartite)
                    return false;
            }
        }

        return true;
    }
};