/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must
take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> entryList(numCourses);
        vector<int> connections(numCourses, 0);
        queue<int> q;
        int queuedCounter = 0;

        for (vector<int> prerequisite : prerequisites)
        {
            entryList[prerequisite[0]].push_back(prerequisite[1]);
            connections[prerequisite[1]]++;
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (connections[i] == 0)
            {
                q.push(i);
                queuedCounter++;
            }
        }

        while (!q.empty())
        {
            for (int i = 0; i < entryList[q.front()].size(); i++)
            {
                connections[ entryList[q.front()][i] ]--;
                if (connections[ entryList[q.front()][i] ] == 0)
                {
                    q.push(entryList[q.front()][i]);
                    queuedCounter++;
                }
            }

            q.pop();
        }

        return queuedCounter == numCourses;
    }
};