/*
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job,
you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties
of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.
*/


class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d)
            return -1;

        const int UNDEFINED = -10;
        const int INVALID = INT32_MAX;
        vector<vector<int>> dp(jobDifficulty.size()+1, vector<int>(d+1, UNDEFINED));


        function<int(int, int)> solve;
        solve = [&](int index, int days) {
            if (index == jobDifficulty.size() || days == 0)
                return (index == jobDifficulty.size() && days == 0 ? 0 : INVALID);
            else if (dp[index][days] != UNDEFINED)
                return dp[index][days];
            else if (days == 1)
                return dp[index][days] = *max_element(jobDifficulty.begin()+index, jobDifficulty.end());
            
            int curr_max = jobDifficulty[index];
            dp[index][days] = INVALID;

            for (int i = index+1; i < jobDifficulty.size(); i++)
            {
                int temp = solve(i, days-1);
                if (temp == INVALID)
                    break;

                dp[index][days] = min(dp[index][days], curr_max + temp);
                curr_max = max(curr_max, jobDifficulty[i]);
            }

            return dp[index][days];
        };

        return solve(0, d);
    }
};