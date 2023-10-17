/*
You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and
rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.
*/


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        int visitedCount = 0;
        int root = -1;


        function<bool(int)> dfs;
        dfs = [&](int vertice) {
            visited[vertice] = true;
            visitedCount++;

            if (leftChild[vertice] != -1)
                if (visited[leftChild[vertice]] || dfs(leftChild[vertice]) == false)
                    return false;

            if (rightChild[vertice] != -1)
                if (visited[rightChild[vertice]] || dfs(rightChild[vertice]) == false)
                    return false;

            return true;
        };

        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
                parent[leftChild[i]] = i;
            
            if (rightChild[i] != -1)
                parent[rightChild[i]] = i;
        }

        root = 0;
        while(parent[root] != -1)
        {
            if (visited[root])
                return false;

            visited[root] = true;
            root = parent[root];
        }

        fill(visited.begin(), visited.end(), false);
        return dfs(root) && visitedCount == n;
    }
};