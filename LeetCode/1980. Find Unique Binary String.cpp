/*
Given an array of strings nums containing n unique binary strings each of length n, return a binary string
of length n that does not appear in nums.
If there are multiple answers, you may return any of them.
*/


class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string binStr;

        binStr.resize(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i][i] == '1')
                binStr[i] = '0';
            else
                binStr[i] = '1';
        }

        return binStr;
    }
};