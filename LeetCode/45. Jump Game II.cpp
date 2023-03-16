/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words,
if you are at nums[i], you can jump to any nums[i + j] where:

    0 <= j <= nums[i] and
    i + j < n

Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
*/


class Solution {
public:
    int jump(vector<int>& nums) {

        nums.back() = 0;
        for (int i = nums.size()-2; i >= 0; i--)
        {
            if (nums[i] == 0)
                nums[i] = nums.size(); // That doesn't reeally mean the number of jumps,
                                       // but indicates that we cannot reach the end from here
            else
                nums[i] = 1 + nums[min((int) nums.size()-1, i+nums[i])];


            for (int j = i+1; nums[j] > nums[i]; j++)
                nums[j] = nums[i];
        }

        return nums[0];
    }
};