/*
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are
no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.
*/


class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobAtStart(100'001);
        vector<int> dp(100'001, -1);
        int maxTime = compress(startTime, endTime);


        function<int(int)> solve;
        solve = [&](int time) {
            if (time > maxTime)
                return 0;
            else if (dp[time] != -1)
                return dp[time];
            
            int maximum = 0;
            for (int& job : jobAtStart[time])
            {
                maximum = max(maximum, profit[job] + solve(endTime[job]));
            }

            return dp[time] = max(maximum, solve(time+1));
        };


        for (int i = 0; i < startTime.size(); i++)
        {
            jobAtStart[startTime[i]].push_back(i);
        }

        return solve(1);
    }

    int compress(vector<int>& startTime, vector<int>& endTime) {
        set<int> s;
        map<int, int> m;

        for (int i = 0; i < startTime.size(); i++)
        {
            s.insert(startTime[i]);
            s.insert(endTime[i]);
        }

        int next = 1;
        for (int it : s)
        {
            m[it] = next;
            next++;
        }

        for (int i = 0; i < startTime.size(); i++)
        {
            startTime[i] = m[startTime[i]];
            endTime[i] = m[endTime[i]];
        }

        return next-1;
    }
};