/*
Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where
edges[i] = [from i, to i] represents a directed edge from node from i to node to i.

Find the smallest set of vertices from which all nodes in the graph are reachable.
It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.
*/


class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> hasNoEntryAdjacent(n, true);
        vector<int> set;

        for (int i = 0; i < edges.size(); i++)
            hasNoEntryAdjacent[edges[i][1]] = false;

        for (int i = 0; i < n; i++)
            if (hasNoEntryAdjacent[i])
                set.push_back(i);

        return set;
    }
};