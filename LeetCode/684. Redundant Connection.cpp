/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional
edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that
already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates
that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are
multiple answers, return the answer that occurs last in the input.
*/


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1);
        vector<int> ans;

        function<int(int)> findParent;
        findParent = [&](int n) {
            if (parent[n] == n)
                return n;
            
            return parent[n] = findParent(parent[n]);
        };

        function<void(int, int)> Union;
        Union = [&](int a, int b) {
            parent[findParent(a)] = findParent(b);
        };


        for (int i = 1; i < parent.size(); i++)
            parent[i] = i;
        
        for (vector<int> edge : edges)
        {
            if (findParent(edge[0]) == findParent(edge[1]))
            {
                ans = edge;
                break;
            }
            
            Union(edge[0], edge[1]);
        }

        return ans;
    }
};