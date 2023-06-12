/*
You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly.
That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

    "a->b" if a != b
    "a" if a == b
*/


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)
            return vector<string>();

        int start = 0;
        vector<string> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if ((i > 0) && (nums[i] > nums[i-1]+1))
            {
                ans.push_back(to_string(nums[start]));
                if (i-1 != start)
                    ans.back() += "->" + to_string(nums[i-1]);

                start = i;
            }
            if (i == nums.size()-1)
            {
                ans.push_back(to_string(nums[start]));
                if (i != start)
                    ans.back() += "->" + to_string(nums[i]);
            }
        }

        return ans;
    }
};