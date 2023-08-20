/*
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive
(i.e. nums[left] + nums[left + 1] + ... + nums[right]).
*/


class NumArray {
    vector<int> sum;

public:
    NumArray(vector<int>& nums) {
        sum.resize(nums.size());

        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            sum[i] = nums[i] + sum[i-1];
    }
    
    int sumRange(int left, int right) {
        if (left == 0)
            return sum[right];
        else
            return (sum[right] - sum[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */