/*
You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri
defeated player loseri in a match.

Return a list answer of size 2 where:

    answer[0] is a list of all players that have not lost any matches.
    answer[1] is a list of all players that have lost exactly one match.

The values in the two lists should be returned in increasing order.

Note:

    You should only consider the players that have played at least one match.
    The testcases will be generated such that no two matches will have the same outcome.
*/


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> losses;
        vector<vector<int>> ans(2);

        for (vector<int>& match : matches)
        {
            losses[match[0]] = max(0, losses[match[0]]);
            losses[match[1]]++;
        }

        for (pair<const int, int>& it : losses)
        {
            if (it.second == 0)      ans[0].push_back(it.first);
            else if (it.second == 1) ans[1].push_back(it.first);
        }

        return ans;
    }
};