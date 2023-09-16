/*
You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting
of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n,
where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to node i.

Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have
the same character assigned to them.
*/


class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> childs(parent.size());
        int longest = 1;


        function<int(int)> dfs;
        dfs = [&](int vertice) {
            priority_queue<int> pq;

            for (int child : childs[vertice])
            {
                if (s[child] != s[vertice])
                    pq.push(dfs(child));
                else
                    dfs(child);
            }


            int first = 0;
            int second = 0;
            if (!pq.empty())
            {
                first = pq.top();
                pq.pop();
            }
            if (!pq.empty())
            {
                second = pq.top();
                pq.pop();
            }

            longest = max(longest, 1 + first + second);
            return 1 + max(first, second);
        };


        // Creating the list of childs for every vertice
        for (int i = 1; i < parent.size(); i++)
        {
            childs[parent[i]].push_back(i);
        }

        dfs(0);
        return longest;
    }
};