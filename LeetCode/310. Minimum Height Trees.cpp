/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words,
any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi]
indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose
any node of the tree as the root. When you select a node x as the root, the result tree has height h.
Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum
height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyList(n);
        vector<int> heights(n+1); // heights[n] will be auxiliary
        vector<bool> visited(n, false);
        vector<int> ans;
        int currentVertice = 0;


        function<int(int)> depth;
        depth = [&](int vertice) {
            visited[vertice] = true;

            int maximum = 0;
            for (int adjacent : adjacencyList[vertice])
            {
                if (!visited[adjacent])
                    maximum = max(maximum, depth(adjacent));
            }

            return heights[vertice] = maximum + 1;
        };


        // Creating the Adjacency List
        for (vector<int> edge : edges)
        {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        // Getting the depth of every vertice
        int first = n;
        int second = n;
        heights[n] = 0;
        visited[0] = true;
        for (int adjacent : adjacencyList[currentVertice])
        {
            heights[adjacent] = depth(adjacent);
            if (heights[adjacent] >= heights[first])
            {
                second = first;
                first = adjacent;
            }
            else if (heights[adjacent] > heights[second])
            {
                second = adjacent;
            }
        }


        int reduce = 1;
        while(true)
        {
            if ((heights[first] - heights[second]) == 0)
            {
                ans.push_back(currentVertice);
                break;
            }
            else if ((heights[first] - heights[second]) == 1)
            {
                ans.push_back(currentVertice);
                ans.push_back(first);
                break;
            }
            else // (heights[first] - heights[second]) >= 2
            {
                int next = first;
                heights[currentVertice] = heights[second] + 1;

                first = currentVertice;
                second = n;
                for (int adjacent : adjacencyList[next])
                {
                    if (heights[adjacent] >= heights[first])
                    {
                        second = first;
                        first = adjacent;
                    }
                    else if (heights[adjacent] > heights[second])
                    {
                        second = adjacent;
                    }
                }

                currentVertice = next;
            }
        }

        return ans;
    }
};