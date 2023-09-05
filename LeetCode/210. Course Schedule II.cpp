/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must
take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers,
return any of them. If it is impossible to finish all courses, return an empty array.
*/


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> entryList(numCourses);
        vector<int> connections(numCourses, 0);
        vector<int> order(numCourses);
        queue<int> q;
        int index = numCourses-1;

        for (vector<int> prerequisite : prerequisites)
        {
            entryList[prerequisite[0]].push_back(prerequisite[1]);
            connections[prerequisite[1]]++;
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (connections[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            order[index] = q.front();
            index--;

            for (int entryAdjacent : entryList[q.front()])
            {
                connections[ entryAdjacent ]--;
                if (connections[ entryAdjacent ] == 0)
                    q.push(entryAdjacent);
            }

            q.pop();
        }

        if (index == -1)
            return order;
        else
            return vector<int>();
    }
};