/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

    For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.
*/


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> sumWays; // pair.first: index;
                                          // pair.second: target value;
                                          // sumWays[pair<index, value>] = number of ways
                                          // to sum up to 'value' from 'index'
        
        function<int(int, int)> dfs;
        dfs = [&](int index, int value) {
            pair<int, int> key(index, value);

            if (index == nums.size())
            {
                if (value == 0)
                    return 1;
                else
                    return 0;
            }
            else if (sumWays.find(key) != sumWays.end())
                return sumWays[key];

            sumWays[key] += dfs(index+1, value+nums[index]);
            sumWays[key] += dfs(index+1, value-nums[index]);

            return sumWays[key];
        };


        return dfs(0, target);
    }
};