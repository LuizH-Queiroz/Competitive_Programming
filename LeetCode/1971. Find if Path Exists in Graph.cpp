/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive).
The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between
vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
*/


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> sets(n, -1);

        for (int i = 0; i < edges.size(); i++)
        {
            Union(sets, edges[i][0], edges[i][1]);
        }

        return (Find(sets, source) == Find(sets, destination));
    }

    void Union(vector<int>& sets, int set1, int set2) {
        if (Find(sets, set1) == Find(sets, set2))
            return;

        if (Weight(sets, set1) < Weight(sets, set2))
        {
            sets[Find(sets, set2)] -= Weight(sets, set1);
            sets[Find(sets, set1)] = Find(sets, set2);
        }
        else
        {
            sets[Find(sets, set1)] -= Weight(sets, set2);
            sets[Find(sets, set2)] = Find(sets, set1);
        }
    }

    int Find(vector<int>& sets, int current) {
        if (sets[current] < 0)
            return current;
        
        return (sets[current] = Find(sets, sets[current]));
    }

    int Weight(vector<int>& sets, int current) {
        if (sets[current] < 0)
            return -sets[current];
        
        return Weight(sets, sets[current]);
    }
};