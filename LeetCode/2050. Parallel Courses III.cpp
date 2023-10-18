/*
You are given an integer n, which indicates that there are n courses labeled from 1 to n.
You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej]
denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship).
Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months it takes to
complete the (i+1)th course.

You must find the minimum number of months needed to complete all the courses following these rules:

You may start taking a course at any time if the prerequisites are met.
Any number of courses can be taken at the same time.
Return the minimum number of months needed to complete all the courses.

Note: The test cases are generated such that it is possible to complete every course (i.e., the graph is
a directed acyclic graph).
*/


class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<bool> noEntry(n+1, true);
        vector<vector<int>> outList(n+1);
        vector<int> timeFrom(n+1, 0);


        function<int(int)> dfs;
        dfs = [&](int vertice) {
            if (timeFrom[vertice] != 0)
                return timeFrom[vertice];

            int maximum = 0;
            for (int adjacent : outList[vertice])
                maximum = max(maximum, dfs(adjacent));

            return timeFrom[vertice] = time[vertice-1] + maximum;
        };

        for (vector<int> relation : relations)
        {
            outList[relation[0]].push_back(relation[1]);
            noEntry[relation[1]] = false;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (noEntry[i])
                ans = max(ans, dfs(i));
        }

        return ans;
    }
};