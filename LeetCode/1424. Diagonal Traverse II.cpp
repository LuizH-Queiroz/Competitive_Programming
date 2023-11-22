/*
Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.
*/


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> groups;
        vector<int> ans;

        for (int i = nums.size()-1; i >= 0; i--)
        {
            for (int j = nums[i].size()-1; j >= 0; j--)
            {
                groups[i+j].push_back(nums[i][j]);
            }
        }

        for (auto it = groups.begin(); it != groups.end(); it++)
        {
            for (auto& val : it->second)
            {
                ans.push_back(val);
            }
        }

        return ans;
    }
};