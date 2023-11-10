/*
There is an integer array nums that consists of n unique elements, but you have forgotten it. However,
you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi]
indicates that the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs,
either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.
*/


class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjacencyList;
        unordered_set<int> visited;
        vector<int> ans(adjacentPairs.size()+1);


        function<void(int, int)> dfs;
        dfs = [&](int vertex, int index) {
            visited.insert(vertex);
            ans[index] = vertex;

            for (int adjacent : adjacencyList[vertex])
            {
                if (visited.find(adjacent) == visited.end())
                {
                    dfs(adjacent, index+1);
                }
            }
        };


        // At the end, there will be two values at the set:
        // both the left and the right side values of the array
        for (vector<int>& pair : adjacentPairs)
        {
            adjacencyList[pair[0]].push_back(pair[1]);
            adjacencyList[pair[1]].push_back(pair[0]);
        }

        int root;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++)
        {
            if (it->second.size() == 1)
            {
                root = it->first;
                break;
            }
        }

        dfs(root, 0);
        return ans;
    }
};